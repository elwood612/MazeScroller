using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class Runner : MonoBehaviour, IRunner
{
    [SerializeField] private TextMeshProUGUI _dialogueBox;
    [SerializeField] private TextMeshProUGUI _answerBox;
    [SerializeField] private Image _glowBox;
    [SerializeField] private Image _runnerFace;
    [SerializeField] private Animator _animator;
    [SerializeField] private ParticleSystem _trailParticles;
    [SerializeField] private Transform _spaceshipTransform;

    private Tile _currentTile;
    private Tile _currentTarget;
    private Tile _nextTarget;
    private Tile _previousTile;
    private List<Tile> _uncrossedTiles = new List<Tile>();
    private List<Tile> _uncrossedTransitionTiles = new List<Tile>();
    private float _currentSpeed;
    private int _colliderCheck = 0;
    private static bool _runnerStopped = true;
    private bool _runnerOffScreen = false;
    private bool _approachingDeadEnd = false;
    public bool _isInTransition = true; // No idea why this has to be public, but it does
    private bool _firstTimeStopping = true;
    private bool _pathfinding = false;
    private bool _gameHasStarted = false;
    private ParticleSystem.MainModule _trailParticlesMainModule;
    private AnimationCurve _speedCurve;
    private AnimationCurve _transitionCurve;

    public static event Action OnTransitionReached;
    public TextMeshProUGUI DialogueBox => _dialogueBox;
    public TextMeshProUGUI AnswerBox => _answerBox;
    public Image GlowBox => _glowBox;
    public Image RunnerFace => _runnerFace;
    public static bool RunnerStopped
    {
        get => _runnerStopped;
        set
        {
            if (_runnerStopped != value) 
            { 
                _runnerStopped = value;
                if (value == true) 
                { 
                    Crystal.ConsecutiveBonus = 1;
                }
            }
        }
    }
    public bool IsInTransition
    {
        get => _isInTransition;
        set => _isInTransition = value;
    }
    public Tile CurrentTile
    {
        get => _currentTile;
        set => _currentTile = value;
    }
    public Tile PreviousTile
    {
        get => _previousTile;
        set => _previousTile = value;
    }

    private void Awake()
    {
        _dialogueBox.transform.GetComponentInParent<Canvas>().enabled = false;
        _speedCurve = GameManager.Instance.RunnerSpeedCurve;
        _transitionCurve = GameManager.Instance.RunnerTransitionCurve;
        _trailParticlesMainModule = _trailParticles.main;
        _trailParticlesMainModule.customSimulationSpace = GameManager.Instance.SampleTileTransform;
    }

    private void OnEnable()
    {
        DrawMaze.OnTileAdded += AddTileToPath;
        Tile.OnTileDestroy += RemoveTileFromPath;
        DialogueManager.OnDialogueOpen += SetAnimatorTrigger;
        GameManager.OnSetupNextStage += ResetFirstStop;
        GameManager.OnStateChanged += GameHasStarted;
    }

    private void OnDisable()
    {
        DrawMaze.OnTileAdded -= AddTileToPath;
        Tile.OnTileDestroy -= RemoveTileFromPath;
        DialogueManager.OnDialogueOpen -= SetAnimatorTrigger;
        GameManager.OnSetupNextStage -= ResetFirstStop;
        GameManager.OnStateChanged -= GameHasStarted;
    }

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
        CalculateSpeed();

        if ((_uncrossedTiles.Count > 0 && !_isInTransition) ||
            (_uncrossedTiles.Count == 0 && _currentTile.IsPreTransitionTile) ||
            (_uncrossedTransitionTiles.Count > 0 && _isInTransition) ||
            _currentTile.IsTransitionTile && GameManager.IsInMainMenu)
        {
            Move();
        }
        else
        {
            if (_firstTimeStopping && !_isInTransition && _gameHasStarted) // Check if this condition applies correctly at startup. Otherwise, dialogue during menu bug!
            {
                _firstTimeStopping = false;
                if (GameManager.IsTutorialOngoing && GameManager.IsTutorialsEnabled) { GameManager.OnNextTutorial?.Invoke(0); }
                else { DialogueManager.Instance.NextComment(GameManager.CurrentStageDialogue); }
                
            }
            RunnerStopped = true;
        }

        GameManager.RunnerHeight = Camera.main.WorldToScreenPoint(transform.position).y / Screen.height;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("TileCenter") && _colliderCheck == 0)
        {
            _colliderCheck++;
            RemoveTileFromPath(_currentTile);
            SetTarget(other.GetComponentInParent<Tile>());
        }
        else if (other.CompareTag("TileDestroyer"))
        {
            _runnerOffScreen = true;
            CalculateNextTargetWrapper(_currentTile);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.CompareTag("TileCenter")) { _colliderCheck = 0; }
    }

    private void CalculateSpeed()
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        float height = screenPos.y / Screen.height;

        if (_isInTransition)
        {
            _currentSpeed = _transitionCurve.Evaluate(height);
        }
        else if (!_isInTransition)
        {
            _currentSpeed = _speedCurve.Evaluate(height) + GameManager.TileSpeed;
        }
    }

    private void Move()
    {
        if (_currentTarget == null || GameManager.IsStageMenuOpen) { return; }
        RunnerStopped = false;
        transform.position = Vector3.MoveTowards(transform.position, _currentTarget.transform.position, Time.deltaTime * _currentSpeed);
    }

    private void SetAnimatorTrigger(bool isOpen)
    {
        _animator.SetBool("IsOpen", isOpen);
    }

    private void SetTarget(Tile tile) // On tile center
    {
        if ((_uncrossedTiles.Count == 0 && !_isInTransition && !_currentTile.IsPreTransitionTile) ||
            (_uncrossedTransitionTiles.Count == 0 && _isInTransition))
        {
            DrawMaze.OnTileAdded += SetTarget;
            _nextTarget = null;
            _currentTarget = null;
            return;
        }
        else
        {
            if (_runnerStopped)
            {
                CalculateNextTargetWrapper(_currentTile);
            }
        }

        if (_nextTarget != null)
        {
            _currentTarget = _nextTarget;
            DrawMaze.OnTileAdded -= SetTarget;
        }
        
        if (_currentTarget != null) { LookAtTile(_currentTarget); }
    }

    private IEnumerator CalculateNextTarget(Tile tile) // On tile edge
    {
        _approachingDeadEnd = _currentTile.NeighborPaths.Count == 1;

        if (_currentTile.NeighborPaths.Count == 0) { yield break; }

        if (_isInTransition || tile.GetNeighborTile(Vector3.forward).IsTransitionTile) 
        {
            //_currentTile.DebugChoice = "Transition choice";
            _nextTarget = _currentTile.GetNeighborTile(Vector3.forward); 
            yield break;
        }

        Tile pathfindingTarget = tile;
        if (_uncrossedTiles.Count > 0) { pathfindingTarget = _uncrossedTiles[_uncrossedTiles.Count - 1]; }
        else if (_uncrossedTransitionTiles.Count > 0) { pathfindingTarget = _uncrossedTransitionTiles[0]; }

        if (_runnerOffScreen)
        {
            yield return new WaitUntil(() => ExecutePathfinding(_currentTile, pathfindingTarget));
            _nextTarget = GetPathfindingPath(_currentTile);
            _runnerOffScreen = false;
            yield break;
        }

        if (GetPathfindingPath(_currentTile) != _currentTile)
        {
            _nextTarget = GetPathfindingPath(_currentTile);
            yield break;
        }

        switch (tile.NeighborPaths.Count)
        {
            case 1:
                // DEBUG
                //if (_uncrossedTiles.Count > 1) // confirmed this isn't the issue
                //{
                //    foreach (Tile t in _uncrossedTiles)
                //    {
                //        t.DebugUncrossedTile = true; // debug
                //    }
                //}
                //goto case 2;
            case 2:
                if (GetOldestCrossedPath(_currentTile) != _currentTile)
                {
                    _nextTarget = GetOldestCrossedPath(_currentTile);
                }
                else
                {
                    yield return new WaitUntil(() => ExecutePathfinding(_currentTile, pathfindingTarget));
                    _nextTarget = GetPathfindingPath(_currentTile);
                }
                break;
            case 3:
            case 4:
                if (GetFirstUncrossedPath(_currentTile) != _currentTile)
                {
                    _nextTarget = GetFirstUncrossedPath(_currentTile);
                }
                else
                {
                    yield return new WaitUntil(() => ExecutePathfinding(_currentTile, pathfindingTarget));
                    _nextTarget = GetPathfindingPath(_currentTile);
                }
                break;
            default:
                _nextTarget = tile;
                break;
        }
    }

    private Tile GetFirstUncrossedPath(Tile tile)
    {
        _pathfinding = false;
        //tile.DebugChoice = "First uncrossed path";
        float firstDrawn = Mathf.Infinity;
        Tile toReturn = tile;

        foreach (Wall wall in tile.NeighborPaths)
        {
            if (wall.Crossings > 0) { continue; }
            Vector3 direction = wall.transform.position - tile.transform.position;
            if (wall.TimeDrawn < firstDrawn)
            {
                firstDrawn = wall.TimeDrawn;
                toReturn = tile.GetNeighborTile(direction);
            }
        }
        return toReturn;
    }

    private Tile Arbitration(Tile tile)
    {
        Tile toReturn = tile;
        foreach (Wall wall in tile.NeighborPaths)
        {
            Vector3 direction = wall.transform.position - tile.transform.position;
            if (tile.GetNeighborTile(direction).Crossings == 0)
            {
                return tile.GetNeighborTile(direction);
            }
        }
        return toReturn;
    }

    private Tile GetOldestCrossedPath(Tile tile)
    {
        _pathfinding = false;
        float firstCrossed = Mathf.Infinity;
        Tile toReturn = tile;
        bool foundUncrossedPath = false;
        float wall1time = 0, wall2time = 0;
        Wall wall1 = tile.NeighborWalls[0];
        Wall wall2 = tile.NeighborWalls[1];
        foreach (Wall wall in tile.NeighborPaths)
        {
            Vector3 direction = wall.transform.position - tile.transform.position;

            if (wall.Crossings == 0) 
            {
                if (foundUncrossedPath) // this means a wall's crossings is incorrectly 0
                {
                    if (Arbitration(tile) != tile) { return Arbitration(tile); }
                    else { Debug.Log("Arbitration failed!"); return Arbitration(tile); } // tmp debug
                }
                else
                {
                    foundUncrossedPath = true;
                    toReturn = tile.GetNeighborTile(direction);
                    continue;
                }
            }
            if (wall.TimeCrossed < firstCrossed)
            {
                firstCrossed = wall.TimeCrossed;
                if (wall1time == 0) { wall1time = wall.TimeCrossed; wall1 = wall; }
                else if (wall2time == 0) { wall2time = wall.TimeCrossed; wall2 = wall; }
                toReturn = tile.GetNeighborTile(direction);
            }
        }
        //tile.DebugChoice = tile.NeighborPaths.Count + " paths available, wall1 = " + wall1time + ", wall2 = " + wall2time
        //    + ", wall1X = " + wall1.Crossings + ", wall2X = " + wall2.Crossings;
        return toReturn;
    }

    private Tile GetPathfindingPath(Tile tile)
    {
        _pathfinding = true;
        //tile.DebugChoice = "Pathfinding path";
        Tile toReturn = tile;
        foreach (Wall wall in tile.NeighborPaths)
        {
            if (!wall.IsPathfindingPath) { continue; }
            else
            {
                toReturn = tile.GetNeighborTile(wall.transform.position - tile.transform.position);
            }
        }
        return toReturn;
    }

    private bool ExecutePathfinding(Tile startTile, Tile endTile)
    {
        ClearPathfinding(); // should help with bugs

        Queue<Tile> openSet = new Queue<Tile>();
        HashSet<Tile> closedSet = new HashSet<Tile>();
        openSet.Enqueue(startTile);

        while (openSet.Count > 0)
        {
            Tile currentTile = openSet.Dequeue();
            closedSet.Add(currentTile);

            if (currentTile == endTile)
            {
                RetracePathfindingPath(startTile, endTile);
                return true;
            }

            foreach (Wall wall in currentTile.NeighborPaths)
            {
                Tile neighborTile = currentTile.GetNeighborTile(wall.transform.position - currentTile.transform.position);
                if (closedSet.Contains(neighborTile)) { continue; }
                if (!openSet.Contains(neighborTile)) 
                { 
                    openSet.Enqueue(neighborTile);
                    neighborTile.PathfindingParent = currentTile;
                }
            }
        }
        Debug.Log("Whelp, something went wrong, teleporting to safety.");
        Teleport(endTile);
        return true;
    }

    // Not quite working
    // There shouldn't be pathfinding happening AFTER the teleport (OnTileDrawn), yet there is
    private void Teleport(Tile endTile)
    {
        ClearPathfinding();
        
        //_runnerStopped = true;
        _runnerOffScreen = false;
        _currentTile = endTile;
        _currentTarget = endTile;
        
        ResetUncrossedTiles();

        transform.position = endTile.transform.position;
    }

    private void ClearPathfinding()
    {
        foreach (Tile tile in BoardManager.AllTiles) { tile.PathfindingParent = null; }
        foreach (Wall wall in BoardManager.AllWalls) { wall.IsPathfindingPath = false; }
    }

    private void ResetUncrossedTiles()
    {
        _uncrossedTiles.Clear();
        foreach (Tile tile in BoardManager.AllTiles)
        {
            if (tile.IsPartOfMaze && tile.Crossings == 0) { _uncrossedTiles.Add(tile); }
        }
    }

    private void RetracePathfindingPath(Tile startTile, Tile finishTile)
    {
        Tile currentTile = finishTile;
        while (currentTile != startTile)
        {
            currentTile.GetWallBetween(currentTile.PathfindingParent).IsPathfindingPath = true;
            currentTile = currentTile.PathfindingParent;
        }
    }

    private void AddTileToPath(Tile tile)
    {
        if (!tile.IsStartingTile && !tile.IsTransitionTile) { _uncrossedTiles.Add(tile); }
        if (!tile.IsStartingTile && tile.IsTransitionTile) { _uncrossedTransitionTiles.Add(tile); }
        if (_approachingDeadEnd) { CalculateNextTargetWrapper(_currentTile); }
    }

    private void RemoveTileFromPath(Tile tile)
    {
        if (_uncrossedTiles.Contains(tile)) { _uncrossedTiles.Remove(tile); }
        if (_uncrossedTransitionTiles.Contains(tile)) { _uncrossedTransitionTiles.Remove(tile); }
    }

    private void ResetFirstStop()
    {
        _firstTimeStopping = true;
    }

    private void GameHasStarted(GameState state)
    {
        if (state == GameState.Progressing && !_gameHasStarted) { _gameHasStarted = true; }
    }

    private void LookAtTile(Tile target)
    {
        Vector3 lookAt;
        if (_currentTile == null) { lookAt = target.transform.position - _spaceshipTransform.position; }
        else { lookAt = target.transform.position - _currentTile.transform.position; }
        if (lookAt.sqrMagnitude > float.Epsilon)
        {
            _spaceshipTransform.forward = lookAt;
        }
    }

    public void CalculateNextTargetWrapper(Tile tile)
    {
        StartCoroutine(CalculateNextTarget(tile));
    }

    public void BeginTransition()
    {
        _isInTransition = true;
        GameManager.IsRunnerInTransition = true;
        OnTransitionReached?.Invoke();
    }

    public void BeginStage()
    {
        _isInTransition = false;
        GameManager.IsRunnerInTransition = false;
        //_currentTile.ParentRow.IsHighestDrawnRow = true;
        BoardManager.SetHighestRow(_currentTile.ParentRow);
    }

    public void SetCurrentTile(Tile tile)
    {
        _currentTile = tile;
    }

    public void OnDialogueBoxClick()
    {
        DialogueManager.Instance.NextSentence();
        AudioManager.Instance.UIClick.Play();
    }

    private void OnDrawGizmos()
    {
        if (_pathfinding) { Gizmos.DrawSphere(transform.position + new Vector3(0, 1, 0), 3f); }
        else { Gizmos.DrawSphere(transform.position, 0.1f); }
    }
}
