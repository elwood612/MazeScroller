#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

// System.Action`1<System.Boolean>
struct Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C;
// System.Action`1<UnityEngine.GameObject>
struct Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C;
// System.Action`1<GameState>
struct Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978;
// System.Action`1<System.Int32>
struct Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404;
// System.Action`1<System.Int32Enum>
struct Action_1_tC926860F20D428DA3E93D6FBA36420E904DD903B;
// System.Action`1<System.Object>
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87;
// System.Action`1<System.String>
struct Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A;
// System.Action`1<TMPro.TMP_TextInfo>
struct Action_1_tB93AB717F9D419A1BEC832FF76E74EAA32184CC1;
// System.Action`2<System.Int32,System.Int32>
struct Action_2_tD7438462601D3939500ED67463331FE00CFFBDB8;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>
struct Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180;
// System.Collections.Generic.Dictionary`2<System.UInt32,UnityEngine.TextCore.Glyph>
struct Dictionary_2_tC61348D10610A6B3D7B65102D82AC3467D59EAA7;
// System.Collections.Generic.Dictionary`2<System.UInt32,TMPro.TMP_Character>
struct Dictionary_2_tCB5FEF8D6CEA1557D9B9BA25946AD6BF3E6C14D0;
// System.Func`3<System.Int32,System.String,TMPro.TMP_FontAsset>
struct Func_3_tC721DF8CDD07ED66A4833A19A2ED2302608C906C;
// System.Func`3<System.Int32,System.String,TMPro.TMP_SpriteAsset>
struct Func_3_t6F6D9932638EA1A5A45303C6626C818C25D164E5;
// System.Collections.Generic.HashSet`1<System.Int32>
struct HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2;
// System.Collections.Generic.HashSet`1<System.UInt32>
struct HashSet_1_t5DD20B42149A11AEBF12A75505306E6EFC34943A;
// System.Collections.Generic.List`1<UnityEngine.CanvasGroup>
struct List_1_t2CDCA768E7F493F5EDEBC75AEB200FD621354E35;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B;
// System.Collections.Generic.List`1<UnityEngine.TextCore.Glyph>
struct List_1_t95DB74B8EE315F8F92B7B96D93C901C8C3F6FE2C;
// System.Collections.Generic.List`1<UnityEngine.TextCore.GlyphRect>
struct List_1_t425D3A455811E316D2DF73E46CF9CD90A4341C1B;
// System.Collections.Generic.List`1<UnityEngine.UI.Image>
struct List_1_tE6BB71ABF15905EFA2BE92C38A2716547AEADB19;
// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
// System.Collections.Generic.List`1<TMPro.TMP_Character>
struct List_1_tCE1ACAA0C2736A7797B2C134895298CAB10BEB5E;
// System.Collections.Generic.List`1<TMPro.TMP_FontAsset>
struct List_1_t06C3ABB0C6F2347B32881E33D154431EADAE3ECF;
// System.Collections.Generic.List`1<TMPro.TMP_Glyph>
struct List_1_tAB7976FADCF872E418770E60783056C23394843D;
// System.Collections.Generic.List`1<System.UInt32>
struct List_1_t9B68833848E4C4D7F623C05F6B77F0449396354A;
// System.Collections.Generic.Queue`1<System.String>
struct Queue_1_t55768C6731D974992BF9775CEA33AAFE7F51CF31;
// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween>
struct TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4;
// TMPro.TMP_TextProcessingStack`1<System.Int32>[]
struct TMP_TextProcessingStack_1U5BU5D_t08293E0BB072311BB96170F351D1083BCA97B9B2;
// UnityEngine.AudioSource[]
struct AudioSourceU5BU5D_tBBF6E920E0DC80D53D4BB2A8D4C80D244EF170B2;
// System.Boolean[]
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// UnityEngine.Color32[]
struct Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259;
// System.Decimal[]
struct DecimalU5BU5D_t93BA0C88FA80728F73B792EE1A5199D0C060B615;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// Dialogue[]
struct DialogueU5BU5D_tDFA7242FC4BAE908FF3783F71719173C548502BB;
// TMPro.FontWeight[]
struct FontWeightU5BU5D_t2A406B5BAB0DD0F06E7F1773DB062E4AF98067BA;
// UnityEngine.GameObject[]
struct GameObjectU5BU5D_tFF67550DFCE87096D7A3734EA15B75896B2722CF;
// TMPro.HighlightState[]
struct HighlightStateU5BU5D_tA878A0AF1F4F52882ACD29515AADC277EE135622;
// TMPro.HorizontalAlignmentOptions[]
struct HorizontalAlignmentOptionsU5BU5D_t4D185662282BFB910D8B9A8199E91578E9422658;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// UnityEngine.Material[]
struct MaterialU5BU5D_t2B1D11C42DB07A4400C0535F92DBB87A2E346D3D;
// TMPro.MaterialReference[]
struct MaterialReferenceU5BU5D_t7491D335AB3E3E13CE9C0F5E931F396F6A02E1F2;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// TMPro.RichTextTagAttribute[]
struct RichTextTagAttributeU5BU5D_t5816316EFD8F59DBC30B9F88E15828C564E47B6D;
// UnityEngine.UI.Selectable[]
struct SelectableU5BU5D_t4160E135F02A40F75A63F787D36F31FEC6FE91A9;
// System.Single[]
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
// UnityEngine.UI.Slider[]
struct SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// StageDialogue[]
struct StageDialogueU5BU5D_t9A4B8E88A6CF81BAF244E49D4CBDF2AB4D9C2B06;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// TMPro.TMP_CharacterInfo[]
struct TMP_CharacterInfoU5BU5D_t297D56FCF66DAA99D8FEA7C30F9F3926902C5B99;
// TMPro.TMP_ColorGradient[]
struct TMP_ColorGradientU5BU5D_t2F65E8C42F268DFF33BB1392D94BCF5B5087308A;
// TMPro.TMP_FontWeightPair[]
struct TMP_FontWeightPairU5BU5D_t0A3A5955F13FEB2F7329D81BA157110DB99F9F37;
// TMPro.TMP_SubMeshUI[]
struct TMP_SubMeshUIU5BU5D_tC77B263183A59A75345C26152457207EAC3BBF29;
// UnityEngine.Texture2D[]
struct Texture2DU5BU5D_t05332F1E3F7D4493E304C702201F9BE4F9236191;
// System.UInt32[]
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
// TMPro.WordWrapState[]
struct WordWrapStateU5BU5D_t473D59C9DBCC949CE72EF1EB471CBA152A6CEAC9;
// TMPro.TMP_Text/UnicodeChar[]
struct UnicodeCharU5BU5D_t67F27D09F8EB28D2C42DFF16FE60054F157012F5;
// System.Action
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07;
// UnityEngine.Animation
struct Animation_t6593B06C39E3B139808B19F2C719C860F3F61040;
// UnityEngine.AnimationClip
struct AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712;
// UnityEngine.AnimationCurve
struct AnimationCurve_tCBFFAAD05CEBB35EF8D8631BD99914BE1A6BB354;
// UnityEngine.UI.AnimationTriggers
struct AnimationTriggers_tA0DC06F89C5280C6DD972F6F4C8A56D7F4F79074;
// AudioManager
struct AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613;
// UnityEngine.AudioSource
struct AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299;
// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA;
// UnityEngine.UI.Button
struct Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098;
// ButtonToggle
struct ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D;
// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26;
// UnityEngine.CanvasRenderer
struct CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// DialogueManager
struct DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241;
// TMPro.FaceInfo_Legacy
struct FaceInfo_Legacy_t23B118EFD5AB7162515ABF18C0212DF155CCF7B8;
// UnityEngine.Font
struct Font_tC95270EA3198038970422D78B74A7F2E218A96B6;
// GM_Settings
struct GM_Settings_tACC8EDD99D4AE7595B5800679E91C7092AC6157C;
// GameManager
struct GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.Collections.IEnumerator
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
// IRunner
struct IRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F;
// TMPro.ITextPreprocessor
struct ITextPreprocessor_tDBB49C8B68D7B80E8D233B9D9666C43981EFAAB9;
// UnityEngine.UI.Image
struct Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E;
// TMPro.KerningTable
struct KerningTable_t040C3FE3B519B12AADE1C5B00628581551D5AB6B;
// UnityEngine.UI.LayoutElement
struct LayoutElement_tB1F24CC11AF4AA87015C8D8EE06D22349C5BF40A;
// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3;
// UnityEngine.Mesh
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// UnityEngine.UI.RectMask2D
struct RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670;
// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// UnityEngine.UI.Selectable
struct Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712;
// UnityEngine.UI.Slider
struct Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F;
// UnityEngine.Sprite
struct Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99;
// StageDialogue
struct StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD;
// System.String
struct String_t;
// TMPro.TMP_Character
struct TMP_Character_t7D37A55EF1A9FF6D0BFE6D50E86A00F80E7FAF35;
// TMPro.TMP_ColorGradient
struct TMP_ColorGradient_t17B51752B4E9499A1FF7D875DCEC1D15A0F4AEBB;
// TMPro.TMP_FontAsset
struct TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160;
// TMPro.TMP_FontFeatureTable
struct TMP_FontFeatureTable_t726A09E64FDF682A8FFE294BB6CFE7747F6C40EA;
// TMPro.TMP_SpriteAnimator
struct TMP_SpriteAnimator_t2E0F016A61CA343E3222FF51E7CF0E53F9F256E4;
// TMPro.TMP_SpriteAsset
struct TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39;
// TMPro.TMP_Style
struct TMP_Style_tA9E5B1B35EBFE24EF980CEA03251B638282E120C;
// TMPro.TMP_StyleSheet
struct TMP_StyleSheet_t70C71699F5CB2D855C361DBB78A44C901236C859;
// TMPro.TMP_Text
struct TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9;
// TMPro.TMP_TextElement
struct TMP_TextElement_t262A55214F712D4274485ABE5676E5254B84D0A5;
// TMPro.TMP_TextInfo
struct TMP_TextInfo_t09A8E906329422C3F0C059876801DD695B8D524D;
// TMPro.TextMeshProUGUI
struct TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957;
// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
// UIManager
struct UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648;
// UnityEngine.Events.UnityAction
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7;
// UnityEngine.UI.VertexHelper
struct VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3;
// UnityEngine.WaitForSecondsRealtime
struct WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01;
// UnityEngine.UI.Button/ButtonClickedEvent
struct ButtonClickedEvent_t8EA72E90B3BD1392FB3B3EF167D5121C23569E4C;
// UnityEngine.Canvas/WillRenderCanvases
struct WillRenderCanvases_tA4A6E66DBA797DCB45B995DBA449A9D1D80D0FBC;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent
struct CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8;
// UnityEngine.UI.Slider/SliderEvent
struct SliderEvent_t92A82EF6C62E15AF92B640FE2D960E877E8C6555;
// UIManager/<BankStars>d__64
struct U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B;
// UIManager/<EndCreditsRoll>d__72
struct U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1;
// UIManager/<FinishSentence>d__58
struct U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A;
// UIManager/<HintDialogue>d__73
struct U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2;
// UIManager/<MainMenuReset>d__71
struct U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B;
// UIManager/<TypeSentence>d__57
struct U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B;

IL2CPP_EXTERN_C RuntimeClass* Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Row_t1EE15C0BD0EC4753FA23C96884DE1DE136C4DB19_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SaveData_tCAF56A3D01300E493D55A0B105DAA8D6F2015C1C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral15E812F5755E8FB8F14234EC436436A5686DEAF4;
IL2CPP_EXTERN_C String_t* _stringLiteral508B359F5800B4F321A17F057E49D729C99EB0A9;
IL2CPP_EXTERN_C String_t* _stringLiteral70DFB3A443EFAAF00DA135342763575F1A90FA54;
IL2CPP_EXTERN_C String_t* _stringLiteral86279004B384FE920D53266948671806A3AF46C2;
IL2CPP_EXTERN_C String_t* _stringLiteral91FA505304EDB1B3A1E99C1CE4AB8C2896809462;
IL2CPP_EXTERN_C String_t* _stringLiteralC84BECFBE67D1CE6878DF6A48AC0DE515B4A85B1;
IL2CPP_EXTERN_C String_t* _stringLiteralCF5CB1E669F53D0126E0AB9DF27AE87BED33C783;
IL2CPP_EXTERN_C String_t* _stringLiteralD1FD6003B70EF875A3B4801CB84EDB7013372DE2;
IL2CPP_EXTERN_C String_t* _stringLiteralD3851214599FE0EFD555278BDD073CEEEE857BE5;
IL2CPP_EXTERN_C String_t* _stringLiteralD976CA0967453E34567684E0B79F556ED6E06573;
IL2CPP_EXTERN_C String_t* _stringLiteralD99605E29810F93D7DAE4EFBB764C41AF4E80D32;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralF2F1837B99915AFFC32DA9765ABF5788B4212459;
IL2CPP_EXTERN_C String_t* _stringLiteralFD776C52B66598466031D7D1332E578D36A80810;
IL2CPP_EXTERN_C const RuntimeMethod* ButtonToggle_UpdateTutorialToggle_m17E2962CFBCA6833FF0830840AAE3A717434C949_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponentInChildren_TisTextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957_m60A1B193FDBBFB3719065622DB5E0BB21CA4ABDC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponentInParent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m0EE7FD91A12A618B79D1B60D2ED73142D7CD65E9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m07D362A07C19B36C2FD1B4DC79DD99903D4DA95D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m96F4B0BD0A5485C8E8CC57D961DF6F1FA256AF27_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_m7236EBE1CFCB6533F96E030500D322B13D0CA5A4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisIRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_m4917A327E1DA277C56EA59748DD449F82FF7B190_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Clear_m32D399BDD753B5BD6CE27560249096418F3F0867_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_GetEnumerator_mA843D26C63E5963415DFCA6E49DFA27AFD9C75E8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CBankStarsU3Ed__64_System_Collections_IEnumerator_Reset_mC6DDFFC1B8C066EAF53F9B3E8D29BFC724241213_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CEndCreditsRollU3Ed__72_System_Collections_IEnumerator_Reset_m7D4782D4CA20065755C789F61F741C9F363F13B5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CFinishSentenceU3Ed__58_System_Collections_IEnumerator_Reset_m9BFFBDFA9138A35F75751D01AB6FEF52C32BBEC2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CHintDialogueU3Ed__73_System_Collections_IEnumerator_Reset_m4D107AF061074F6CFCBE2DB4995C1C468C580453_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CMainMenuResetU3Ed__71_System_Collections_IEnumerator_Reset_m9240752811EDAF53425A69F3F82AA10BCFDCD4A4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CTypeSentenceU3Ed__57_System_Collections_IEnumerator_Reset_m23A5F712ECE79A24516A88B21EE5FF5D37AD0608_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_AssignDialogueBox_mA02ACC08EF1AE90E9BF2FCDB6B88848362E6948F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_BeginStage_m9765DBBC150EE6472BEFD406A5AE8DD387EB77AC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_BlackScreenFadeIn_mA8C7A7488676524CC74004C93A22A6C255B2DC5F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_BlackScreenFadeOut_mA74743737254BACC2CC126AB239416EAA19FD143_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_EndStage_mBB8377AFDBC3E9C61A70CF7CCCBD4737BD537270_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_GainStar_mC2B8C93E19707CD2CC1DA97214AFE05B52B0836A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_HideDialogueBox_mF51F524D06B33CD86E91434FCA908277DCADA981_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_MainMenu_m266054608AA5ECFD724D14077C1800FC85CD5673_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_UpdateCompassionateSlider_m1EAC1195B36B29BCA99A40352F55DFD1EFF9769C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_UpdateDialogueBox_mA80B91F523DE326AADA4C78971738159CCB0C0E6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UIManager_UpdateSpeedBonus_mC3095028203E1D1AC7AD695164B5B727CD50DB5C_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <Module>
struct U3CModuleU3E_tCA7A04B0FFDC3B5F01F023E53ADE58AB2FB7790D 
{
};

// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	GameObjectU5BU5D_tFF67550DFCE87096D7A3734EA15B75896B2722CF* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// UnityEngine.CustomYieldInstruction
struct CustomYieldInstruction_t6B81A50D5D210C1ACAAE247FB53B65CDFFEB7617  : public RuntimeObject
{
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
};
// Native definition for COM marshalling of UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
};

// UIManager/<BankStars>d__64
struct U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B  : public RuntimeObject
{
	// System.Int32 UIManager/<BankStars>d__64::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object UIManager/<BankStars>d__64::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// UIManager UIManager/<BankStars>d__64::<>4__this
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* ___U3CU3E4__this_2;
	// System.Int32 UIManager/<BankStars>d__64::stars
	int32_t ___stars_3;
	// System.Int32 UIManager/<BankStars>d__64::<i>5__2
	int32_t ___U3CiU3E5__2_4;
};

// UIManager/<EndCreditsRoll>d__72
struct U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1  : public RuntimeObject
{
	// System.Int32 UIManager/<EndCreditsRoll>d__72::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object UIManager/<EndCreditsRoll>d__72::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// UIManager UIManager/<EndCreditsRoll>d__72::<>4__this
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* ___U3CU3E4__this_2;
};

// UIManager/<FinishSentence>d__58
struct U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A  : public RuntimeObject
{
	// System.Int32 UIManager/<FinishSentence>d__58::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object UIManager/<FinishSentence>d__58::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// UIManager UIManager/<FinishSentence>d__58::<>4__this
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* ___U3CU3E4__this_2;
};

// UIManager/<HintDialogue>d__73
struct U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2  : public RuntimeObject
{
	// System.Int32 UIManager/<HintDialogue>d__73::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object UIManager/<HintDialogue>d__73::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// UIManager UIManager/<HintDialogue>d__73::<>4__this
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* ___U3CU3E4__this_2;
};

// UIManager/<MainMenuReset>d__71
struct U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B  : public RuntimeObject
{
	// System.Int32 UIManager/<MainMenuReset>d__71::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object UIManager/<MainMenuReset>d__71::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// UIManager UIManager/<MainMenuReset>d__71::<>4__this
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* ___U3CU3E4__this_2;
};

// UIManager/<TypeSentence>d__57
struct U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B  : public RuntimeObject
{
	// System.Int32 UIManager/<TypeSentence>d__57::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object UIManager/<TypeSentence>d__57::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// UIManager UIManager/<TypeSentence>d__57::<>4__this
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* ___U3CU3E4__this_2;
	// System.String UIManager/<TypeSentence>d__57::sentence
	String_t* ___sentence_3;
	// System.Char[] UIManager/<TypeSentence>d__57::<>7__wrap1
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___U3CU3E7__wrap1_4;
	// System.Int32 UIManager/<TypeSentence>d__57::<>7__wrap2
	int32_t ___U3CU3E7__wrap2_5;
};

// System.Collections.Generic.List`1/Enumerator<UnityEngine.GameObject>
struct Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60 
{
	// System.Collections.Generic.List`1<T> System.Collections.Generic.List`1/Enumerator::_list
	List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* ____list_0;
	// System.Int32 System.Collections.Generic.List`1/Enumerator::_index
	int32_t ____index_1;
	// System.Int32 System.Collections.Generic.List`1/Enumerator::_version
	int32_t ____version_2;
	// T System.Collections.Generic.List`1/Enumerator::_current
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____current_3;
};

// System.Collections.Generic.List`1/Enumerator<System.Object>
struct Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A 
{
	// System.Collections.Generic.List`1<T> System.Collections.Generic.List`1/Enumerator::_list
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ____list_0;
	// System.Int32 System.Collections.Generic.List`1/Enumerator::_index
	int32_t ____index_1;
	// System.Int32 System.Collections.Generic.List`1/Enumerator::_version
	int32_t ____version_2;
	// T System.Collections.Generic.List`1/Enumerator::_current
	RuntimeObject* ____current_3;
};

// TMPro.TMP_TextProcessingStack`1<TMPro.FontWeight>
struct TMP_TextProcessingStack_1_tA5C8CED87DD9E73F6359E23B334FFB5B6F813FD4 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	FontWeightU5BU5D_t2A406B5BAB0DD0F06E7F1773DB062E4AF98067BA* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	int32_t ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// TMPro.TMP_TextProcessingStack`1<TMPro.HorizontalAlignmentOptions>
struct TMP_TextProcessingStack_1_t243EA1B5D7FD2295D6533B953F0BBE8F52EFB8A0 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	HorizontalAlignmentOptionsU5BU5D_t4D185662282BFB910D8B9A8199E91578E9422658* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	int32_t ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// TMPro.TMP_TextProcessingStack`1<System.Int32>
struct TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	int32_t ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// TMPro.TMP_TextProcessingStack`1<System.Single>
struct TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	float ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// TMPro.TMP_TextProcessingStack`1<TMPro.TMP_ColorGradient>
struct TMP_TextProcessingStack_1_tC8FAEB17246D3B171EFD11165A5761AE39B40D0C 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	TMP_ColorGradientU5BU5D_t2F65E8C42F268DFF33BB1392D94BCF5B5087308A* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	TMP_ColorGradient_t17B51752B4E9499A1FF7D875DCEC1D15A0F4AEBB* ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	// System.Char System.Char::m_value
	Il2CppChar ___m_value_0;
};

// UnityEngine.Color
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	// System.Single UnityEngine.Color::r
	float ___r_0;
	// System.Single UnityEngine.Color::g
	float ___g_1;
	// System.Single UnityEngine.Color::b
	float ___b_2;
	// System.Single UnityEngine.Color::a
	float ___a_3;
};

// UnityEngine.Color32
struct Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			// System.Int32 UnityEngine.Color32::rgba
			int32_t ___rgba_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___rgba_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			// System.Byte UnityEngine.Color32::r
			uint8_t ___r_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___r_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___g_2_OffsetPadding[1];
			// System.Byte UnityEngine.Color32::g
			uint8_t ___g_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___g_2_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___g_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___b_3_OffsetPadding[2];
			// System.Byte UnityEngine.Color32::b
			uint8_t ___b_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___b_3_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___b_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___a_4_OffsetPadding[3];
			// System.Byte UnityEngine.Color32::a
			uint8_t ___a_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___a_4_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___a_4_forAlignmentOnly;
		};
	};
};

// UnityEngine.DrivenRectTransformTracker
struct DrivenRectTransformTracker_tFB0706C933E3C68E4F377C204FCEEF091F1EE0B1 
{
	union
	{
		struct
		{
		};
		uint8_t DrivenRectTransformTracker_tFB0706C933E3C68E4F377C204FCEEF091F1EE0B1__padding[1];
	};
};

// UnityEngine.TextCore.FaceInfo
struct FaceInfo_t12F0319E555A62CBA1D9E51A16C7963393932756 
{
	// System.Int32 UnityEngine.TextCore.FaceInfo::m_FaceIndex
	int32_t ___m_FaceIndex_0;
	// System.String UnityEngine.TextCore.FaceInfo::m_FamilyName
	String_t* ___m_FamilyName_1;
	// System.String UnityEngine.TextCore.FaceInfo::m_StyleName
	String_t* ___m_StyleName_2;
	// System.Int32 UnityEngine.TextCore.FaceInfo::m_PointSize
	int32_t ___m_PointSize_3;
	// System.Single UnityEngine.TextCore.FaceInfo::m_Scale
	float ___m_Scale_4;
	// System.Int32 UnityEngine.TextCore.FaceInfo::m_UnitsPerEM
	int32_t ___m_UnitsPerEM_5;
	// System.Single UnityEngine.TextCore.FaceInfo::m_LineHeight
	float ___m_LineHeight_6;
	// System.Single UnityEngine.TextCore.FaceInfo::m_AscentLine
	float ___m_AscentLine_7;
	// System.Single UnityEngine.TextCore.FaceInfo::m_CapLine
	float ___m_CapLine_8;
	// System.Single UnityEngine.TextCore.FaceInfo::m_MeanLine
	float ___m_MeanLine_9;
	// System.Single UnityEngine.TextCore.FaceInfo::m_Baseline
	float ___m_Baseline_10;
	// System.Single UnityEngine.TextCore.FaceInfo::m_DescentLine
	float ___m_DescentLine_11;
	// System.Single UnityEngine.TextCore.FaceInfo::m_SuperscriptOffset
	float ___m_SuperscriptOffset_12;
	// System.Single UnityEngine.TextCore.FaceInfo::m_SuperscriptSize
	float ___m_SuperscriptSize_13;
	// System.Single UnityEngine.TextCore.FaceInfo::m_SubscriptOffset
	float ___m_SubscriptOffset_14;
	// System.Single UnityEngine.TextCore.FaceInfo::m_SubscriptSize
	float ___m_SubscriptSize_15;
	// System.Single UnityEngine.TextCore.FaceInfo::m_UnderlineOffset
	float ___m_UnderlineOffset_16;
	// System.Single UnityEngine.TextCore.FaceInfo::m_UnderlineThickness
	float ___m_UnderlineThickness_17;
	// System.Single UnityEngine.TextCore.FaceInfo::m_StrikethroughOffset
	float ___m_StrikethroughOffset_18;
	// System.Single UnityEngine.TextCore.FaceInfo::m_StrikethroughThickness
	float ___m_StrikethroughThickness_19;
	// System.Single UnityEngine.TextCore.FaceInfo::m_TabWidth
	float ___m_TabWidth_20;
};
// Native definition for P/Invoke marshalling of UnityEngine.TextCore.FaceInfo
struct FaceInfo_t12F0319E555A62CBA1D9E51A16C7963393932756_marshaled_pinvoke
{
	int32_t ___m_FaceIndex_0;
	char* ___m_FamilyName_1;
	char* ___m_StyleName_2;
	int32_t ___m_PointSize_3;
	float ___m_Scale_4;
	int32_t ___m_UnitsPerEM_5;
	float ___m_LineHeight_6;
	float ___m_AscentLine_7;
	float ___m_CapLine_8;
	float ___m_MeanLine_9;
	float ___m_Baseline_10;
	float ___m_DescentLine_11;
	float ___m_SuperscriptOffset_12;
	float ___m_SuperscriptSize_13;
	float ___m_SubscriptOffset_14;
	float ___m_SubscriptSize_15;
	float ___m_UnderlineOffset_16;
	float ___m_UnderlineThickness_17;
	float ___m_StrikethroughOffset_18;
	float ___m_StrikethroughThickness_19;
	float ___m_TabWidth_20;
};
// Native definition for COM marshalling of UnityEngine.TextCore.FaceInfo
struct FaceInfo_t12F0319E555A62CBA1D9E51A16C7963393932756_marshaled_com
{
	int32_t ___m_FaceIndex_0;
	Il2CppChar* ___m_FamilyName_1;
	Il2CppChar* ___m_StyleName_2;
	int32_t ___m_PointSize_3;
	float ___m_Scale_4;
	int32_t ___m_UnitsPerEM_5;
	float ___m_LineHeight_6;
	float ___m_AscentLine_7;
	float ___m_CapLine_8;
	float ___m_MeanLine_9;
	float ___m_Baseline_10;
	float ___m_DescentLine_11;
	float ___m_SuperscriptOffset_12;
	float ___m_SuperscriptSize_13;
	float ___m_SubscriptOffset_14;
	float ___m_SubscriptSize_15;
	float ___m_UnderlineOffset_16;
	float ___m_UnderlineThickness_17;
	float ___m_StrikethroughOffset_18;
	float ___m_StrikethroughThickness_19;
	float ___m_TabWidth_20;
};

// TMPro.FontAssetCreationSettings
struct FontAssetCreationSettings_t2B94078737A72F814E8BC2126F967B94231190DF 
{
	// System.String TMPro.FontAssetCreationSettings::sourceFontFileName
	String_t* ___sourceFontFileName_0;
	// System.String TMPro.FontAssetCreationSettings::sourceFontFileGUID
	String_t* ___sourceFontFileGUID_1;
	// System.Int32 TMPro.FontAssetCreationSettings::pointSizeSamplingMode
	int32_t ___pointSizeSamplingMode_2;
	// System.Int32 TMPro.FontAssetCreationSettings::pointSize
	int32_t ___pointSize_3;
	// System.Int32 TMPro.FontAssetCreationSettings::padding
	int32_t ___padding_4;
	// System.Int32 TMPro.FontAssetCreationSettings::packingMode
	int32_t ___packingMode_5;
	// System.Int32 TMPro.FontAssetCreationSettings::atlasWidth
	int32_t ___atlasWidth_6;
	// System.Int32 TMPro.FontAssetCreationSettings::atlasHeight
	int32_t ___atlasHeight_7;
	// System.Int32 TMPro.FontAssetCreationSettings::characterSetSelectionMode
	int32_t ___characterSetSelectionMode_8;
	// System.String TMPro.FontAssetCreationSettings::characterSequence
	String_t* ___characterSequence_9;
	// System.String TMPro.FontAssetCreationSettings::referencedFontAssetGUID
	String_t* ___referencedFontAssetGUID_10;
	// System.String TMPro.FontAssetCreationSettings::referencedTextAssetGUID
	String_t* ___referencedTextAssetGUID_11;
	// System.Int32 TMPro.FontAssetCreationSettings::fontStyle
	int32_t ___fontStyle_12;
	// System.Single TMPro.FontAssetCreationSettings::fontStyleModifier
	float ___fontStyleModifier_13;
	// System.Int32 TMPro.FontAssetCreationSettings::renderMode
	int32_t ___renderMode_14;
	// System.Boolean TMPro.FontAssetCreationSettings::includeFontFeatures
	bool ___includeFontFeatures_15;
};
// Native definition for P/Invoke marshalling of TMPro.FontAssetCreationSettings
struct FontAssetCreationSettings_t2B94078737A72F814E8BC2126F967B94231190DF_marshaled_pinvoke
{
	char* ___sourceFontFileName_0;
	char* ___sourceFontFileGUID_1;
	int32_t ___pointSizeSamplingMode_2;
	int32_t ___pointSize_3;
	int32_t ___padding_4;
	int32_t ___packingMode_5;
	int32_t ___atlasWidth_6;
	int32_t ___atlasHeight_7;
	int32_t ___characterSetSelectionMode_8;
	char* ___characterSequence_9;
	char* ___referencedFontAssetGUID_10;
	char* ___referencedTextAssetGUID_11;
	int32_t ___fontStyle_12;
	float ___fontStyleModifier_13;
	int32_t ___renderMode_14;
	int32_t ___includeFontFeatures_15;
};
// Native definition for COM marshalling of TMPro.FontAssetCreationSettings
struct FontAssetCreationSettings_t2B94078737A72F814E8BC2126F967B94231190DF_marshaled_com
{
	Il2CppChar* ___sourceFontFileName_0;
	Il2CppChar* ___sourceFontFileGUID_1;
	int32_t ___pointSizeSamplingMode_2;
	int32_t ___pointSize_3;
	int32_t ___padding_4;
	int32_t ___packingMode_5;
	int32_t ___atlasWidth_6;
	int32_t ___atlasHeight_7;
	int32_t ___characterSetSelectionMode_8;
	Il2CppChar* ___characterSequence_9;
	Il2CppChar* ___referencedFontAssetGUID_10;
	Il2CppChar* ___referencedTextAssetGUID_11;
	int32_t ___fontStyle_12;
	float ___fontStyleModifier_13;
	int32_t ___renderMode_14;
	int32_t ___includeFontFeatures_15;
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// TMPro.MaterialReference
struct MaterialReference_tFD98FFFBBDF168028E637446C6676507186F4D0B 
{
	// System.Int32 TMPro.MaterialReference::index
	int32_t ___index_0;
	// TMPro.TMP_FontAsset TMPro.MaterialReference::fontAsset
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___fontAsset_1;
	// TMPro.TMP_SpriteAsset TMPro.MaterialReference::spriteAsset
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___spriteAsset_2;
	// UnityEngine.Material TMPro.MaterialReference::material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___material_3;
	// System.Boolean TMPro.MaterialReference::isDefaultMaterial
	bool ___isDefaultMaterial_4;
	// System.Boolean TMPro.MaterialReference::isFallbackMaterial
	bool ___isFallbackMaterial_5;
	// UnityEngine.Material TMPro.MaterialReference::fallbackMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___fallbackMaterial_6;
	// System.Single TMPro.MaterialReference::padding
	float ___padding_7;
	// System.Int32 TMPro.MaterialReference::referenceCount
	int32_t ___referenceCount_8;
};
// Native definition for P/Invoke marshalling of TMPro.MaterialReference
struct MaterialReference_tFD98FFFBBDF168028E637446C6676507186F4D0B_marshaled_pinvoke
{
	int32_t ___index_0;
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___fontAsset_1;
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___spriteAsset_2;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___material_3;
	int32_t ___isDefaultMaterial_4;
	int32_t ___isFallbackMaterial_5;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___fallbackMaterial_6;
	float ___padding_7;
	int32_t ___referenceCount_8;
};
// Native definition for COM marshalling of TMPro.MaterialReference
struct MaterialReference_tFD98FFFBBDF168028E637446C6676507186F4D0B_marshaled_com
{
	int32_t ___index_0;
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___fontAsset_1;
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___spriteAsset_2;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___material_3;
	int32_t ___isDefaultMaterial_4;
	int32_t ___isFallbackMaterial_5;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___fallbackMaterial_6;
	float ___padding_7;
	int32_t ___referenceCount_8;
};

// UnityEngine.Matrix4x4
struct Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 
{
	// System.Single UnityEngine.Matrix4x4::m00
	float ___m00_0;
	// System.Single UnityEngine.Matrix4x4::m10
	float ___m10_1;
	// System.Single UnityEngine.Matrix4x4::m20
	float ___m20_2;
	// System.Single UnityEngine.Matrix4x4::m30
	float ___m30_3;
	// System.Single UnityEngine.Matrix4x4::m01
	float ___m01_4;
	// System.Single UnityEngine.Matrix4x4::m11
	float ___m11_5;
	// System.Single UnityEngine.Matrix4x4::m21
	float ___m21_6;
	// System.Single UnityEngine.Matrix4x4::m31
	float ___m31_7;
	// System.Single UnityEngine.Matrix4x4::m02
	float ___m02_8;
	// System.Single UnityEngine.Matrix4x4::m12
	float ___m12_9;
	// System.Single UnityEngine.Matrix4x4::m22
	float ___m22_10;
	// System.Single UnityEngine.Matrix4x4::m32
	float ___m32_11;
	// System.Single UnityEngine.Matrix4x4::m03
	float ___m03_12;
	// System.Single UnityEngine.Matrix4x4::m13
	float ___m13_13;
	// System.Single UnityEngine.Matrix4x4::m23
	float ___m23_14;
	// System.Single UnityEngine.Matrix4x4::m33
	float ___m33_15;
};

// UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C 
{
	// UnityEngine.UI.Navigation/Mode UnityEngine.UI.Navigation::m_Mode
	int32_t ___m_Mode_0;
	// System.Boolean UnityEngine.UI.Navigation::m_WrapAround
	bool ___m_WrapAround_1;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnUp
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnDown
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnLeft
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnRight
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};
// Native definition for P/Invoke marshalling of UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C_marshaled_pinvoke
{
	int32_t ___m_Mode_0;
	int32_t ___m_WrapAround_1;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};
// Native definition for COM marshalling of UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C_marshaled_com
{
	int32_t ___m_Mode_0;
	int32_t ___m_WrapAround_1;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};

// UnityEngine.Rect
struct Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D 
{
	// System.Single UnityEngine.Rect::m_XMin
	float ___m_XMin_0;
	// System.Single UnityEngine.Rect::m_YMin
	float ___m_YMin_1;
	// System.Single UnityEngine.Rect::m_Width
	float ___m_Width_2;
	// System.Single UnityEngine.Rect::m_Height
	float ___m_Height_3;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD 
{
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_HighlightedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_PressedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_SelectedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_DisabledSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};
// Native definition for P/Invoke marshalling of UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD_marshaled_pinvoke
{
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};
// Native definition for COM marshalling of UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD_marshaled_com
{
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};

// TMPro.TMP_FontStyleStack
struct TMP_FontStyleStack_t52885F172FADBC21346C835B5302167BDA8020DC 
{
	// System.Byte TMPro.TMP_FontStyleStack::bold
	uint8_t ___bold_0;
	// System.Byte TMPro.TMP_FontStyleStack::italic
	uint8_t ___italic_1;
	// System.Byte TMPro.TMP_FontStyleStack::underline
	uint8_t ___underline_2;
	// System.Byte TMPro.TMP_FontStyleStack::strikethrough
	uint8_t ___strikethrough_3;
	// System.Byte TMPro.TMP_FontStyleStack::highlight
	uint8_t ___highlight_4;
	// System.Byte TMPro.TMP_FontStyleStack::superscript
	uint8_t ___superscript_5;
	// System.Byte TMPro.TMP_FontStyleStack::subscript
	uint8_t ___subscript_6;
	// System.Byte TMPro.TMP_FontStyleStack::uppercase
	uint8_t ___uppercase_7;
	// System.Byte TMPro.TMP_FontStyleStack::lowercase
	uint8_t ___lowercase_8;
	// System.Byte TMPro.TMP_FontStyleStack::smallcaps
	uint8_t ___smallcaps_9;
};

// TMPro.TMP_Offset
struct TMP_Offset_t2262BE4E87D9662487777FF8FFE1B17B0E4438C6 
{
	// System.Single TMPro.TMP_Offset::m_Left
	float ___m_Left_0;
	// System.Single TMPro.TMP_Offset::m_Right
	float ___m_Right_1;
	// System.Single TMPro.TMP_Offset::m_Top
	float ___m_Top_2;
	// System.Single TMPro.TMP_Offset::m_Bottom
	float ___m_Bottom_3;
};

// UnityEngine.Vector2
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	// System.Single UnityEngine.Vector2::x
	float ___x_0;
	// System.Single UnityEngine.Vector2::y
	float ___y_1;
};

// UnityEngine.Vector3
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	// System.Single UnityEngine.Vector3::x
	float ___x_2;
	// System.Single UnityEngine.Vector3::y
	float ___y_3;
	// System.Single UnityEngine.Vector3::z
	float ___z_4;
};

// UnityEngine.Vector4
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	// System.Single UnityEngine.Vector4::x
	float ___x_1;
	// System.Single UnityEngine.Vector4::y
	float ___y_2;
	// System.Single UnityEngine.Vector4::z
	float ___z_3;
	// System.Single UnityEngine.Vector4::w
	float ___w_4;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	// System.Single UnityEngine.WaitForSeconds::m_Seconds
	float ___m_Seconds_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	float ___m_Seconds_0;
};
// Native definition for COM marshalling of UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	float ___m_Seconds_0;
};

// UnityEngine.WaitForSecondsRealtime
struct WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01  : public CustomYieldInstruction_t6B81A50D5D210C1ACAAE247FB53B65CDFFEB7617
{
	// System.Single UnityEngine.WaitForSecondsRealtime::<waitTime>k__BackingField
	float ___U3CwaitTimeU3Ek__BackingField_0;
	// System.Single UnityEngine.WaitForSecondsRealtime::m_WaitUntilTime
	float ___m_WaitUntilTime_1;
};

// TMPro.TMP_Text/SpecialCharacter
struct SpecialCharacter_t6C1DBE8C490706D1620899BAB7F0B8091AD26777 
{
	// TMPro.TMP_Character TMPro.TMP_Text/SpecialCharacter::character
	TMP_Character_t7D37A55EF1A9FF6D0BFE6D50E86A00F80E7FAF35* ___character_0;
	// TMPro.TMP_FontAsset TMPro.TMP_Text/SpecialCharacter::fontAsset
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___fontAsset_1;
	// UnityEngine.Material TMPro.TMP_Text/SpecialCharacter::material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___material_2;
	// System.Int32 TMPro.TMP_Text/SpecialCharacter::materialIndex
	int32_t ___materialIndex_3;
};
// Native definition for P/Invoke marshalling of TMPro.TMP_Text/SpecialCharacter
struct SpecialCharacter_t6C1DBE8C490706D1620899BAB7F0B8091AD26777_marshaled_pinvoke
{
	TMP_Character_t7D37A55EF1A9FF6D0BFE6D50E86A00F80E7FAF35* ___character_0;
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___fontAsset_1;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___material_2;
	int32_t ___materialIndex_3;
};
// Native definition for COM marshalling of TMPro.TMP_Text/SpecialCharacter
struct SpecialCharacter_t6C1DBE8C490706D1620899BAB7F0B8091AD26777_marshaled_com
{
	TMP_Character_t7D37A55EF1A9FF6D0BFE6D50E86A00F80E7FAF35* ___character_0;
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___fontAsset_1;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___material_2;
	int32_t ___materialIndex_3;
};

// TMPro.TMP_Text/TextBackingContainer
struct TextBackingContainer_t33D1CE628E7B26C45EDAC1D87BEF2DD22A5C6361 
{
	// System.UInt32[] TMPro.TMP_Text/TextBackingContainer::m_Array
	UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___m_Array_0;
	// System.Int32 TMPro.TMP_Text/TextBackingContainer::m_Count
	int32_t ___m_Count_1;
};
// Native definition for P/Invoke marshalling of TMPro.TMP_Text/TextBackingContainer
struct TextBackingContainer_t33D1CE628E7B26C45EDAC1D87BEF2DD22A5C6361_marshaled_pinvoke
{
	Il2CppSafeArray/*NONE*/* ___m_Array_0;
	int32_t ___m_Count_1;
};
// Native definition for COM marshalling of TMPro.TMP_Text/TextBackingContainer
struct TextBackingContainer_t33D1CE628E7B26C45EDAC1D87BEF2DD22A5C6361_marshaled_com
{
	Il2CppSafeArray/*NONE*/* ___m_Array_0;
	int32_t ___m_Count_1;
};

// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32>
struct TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// TMPro.TMP_TextProcessingStack`1<TMPro.MaterialReference>
struct TMP_TextProcessingStack_1_tB03E08F69415B281A5A81138F09E49EE58402DF9 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	MaterialReferenceU5BU5D_t7491D335AB3E3E13CE9C0F5E931F396F6A02E1F2* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	MaterialReference_tFD98FFFBBDF168028E637446C6676507186F4D0B ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// UnityEngine.UI.ColorBlock
struct ColorBlock_tDD7C62E7AFE442652FC98F8D058CE8AE6BFD7C11 
{
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_NormalColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_NormalColor_0;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_HighlightedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_HighlightedColor_1;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_PressedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_PressedColor_2;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_SelectedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_SelectedColor_3;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_DisabledColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_DisabledColor_4;
	// System.Single UnityEngine.UI.ColorBlock::m_ColorMultiplier
	float ___m_ColorMultiplier_5;
	// System.Single UnityEngine.UI.ColorBlock::m_FadeDuration
	float ___m_FadeDuration_6;
};

// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	// System.IntPtr UnityEngine.Coroutine::m_Ptr
	intptr_t ___m_Ptr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
};
// Native definition for COM marshalling of UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	intptr_t ___m_Ptr_0;
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	Il2CppMethodPointer ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// System.Exception
struct Exception_t  : public RuntimeObject
{
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t* ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject* ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject* ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips_15;
	// System.Int32 System.Exception::caught_in_unmanaged
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};

// TMPro.Extents
struct Extents_tA2D2F95811D0A18CB7AC3570D2D8F8CD3AF4C4A8 
{
	// UnityEngine.Vector2 TMPro.Extents::min
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___min_2;
	// UnityEngine.Vector2 TMPro.Extents::max
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___max_3;
};

// TMPro.HighlightState
struct HighlightState_tE4F50287E5E2E91D42AB77DEA281D88D3AD6A28B 
{
	// UnityEngine.Color32 TMPro.HighlightState::color
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___color_0;
	// TMPro.TMP_Offset TMPro.HighlightState::padding
	TMP_Offset_t2262BE4E87D9662487777FF8FFE1B17B0E4438C6 ___padding_1;
};

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Object::m_CachedPtr
	intptr_t ___m_CachedPtr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr_0;
};
// Native definition for COM marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr_0;
};

// Unity.Profiling.ProfilerMarker
struct ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD 
{
	// System.IntPtr Unity.Profiling.ProfilerMarker::m_Ptr
	intptr_t ___m_Ptr_0;
};

// TMPro.VertexGradient
struct VertexGradient_t2C057B53C0EA6E987C2B7BAB0305E686DA1C9A8F 
{
	// UnityEngine.Color TMPro.VertexGradient::topLeft
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___topLeft_0;
	// UnityEngine.Color TMPro.VertexGradient::topRight
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___topRight_1;
	// UnityEngine.Color TMPro.VertexGradient::bottomLeft
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___bottomLeft_2;
	// UnityEngine.Color TMPro.VertexGradient::bottomRight
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___bottomRight_3;
};

// TMPro.TMP_TextProcessingStack`1<TMPro.HighlightState>
struct TMP_TextProcessingStack_1_t57AECDCC936A7FF1D6CF66CA11560B28A675648D 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	HighlightStateU5BU5D_tA878A0AF1F4F52882ACD29515AADC277EE135622* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	HighlightState_tE4F50287E5E2E91D42AB77DEA281D88D3AD6A28B ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.Motion
struct Motion_tBCD49FBF5608AD21FC03B63C8182FABCEF2707AC  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
// Native definition for P/Invoke marshalling of UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_pinvoke : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
};
// Native definition for COM marshalling of UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_com : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// TMPro.TMP_LineInfo
struct TMP_LineInfo_tB75C1965B58DB7B3A046C8CA55AD6AB92B6B17B3 
{
	// System.Int32 TMPro.TMP_LineInfo::controlCharacterCount
	int32_t ___controlCharacterCount_0;
	// System.Int32 TMPro.TMP_LineInfo::characterCount
	int32_t ___characterCount_1;
	// System.Int32 TMPro.TMP_LineInfo::visibleCharacterCount
	int32_t ___visibleCharacterCount_2;
	// System.Int32 TMPro.TMP_LineInfo::spaceCount
	int32_t ___spaceCount_3;
	// System.Int32 TMPro.TMP_LineInfo::wordCount
	int32_t ___wordCount_4;
	// System.Int32 TMPro.TMP_LineInfo::firstCharacterIndex
	int32_t ___firstCharacterIndex_5;
	// System.Int32 TMPro.TMP_LineInfo::firstVisibleCharacterIndex
	int32_t ___firstVisibleCharacterIndex_6;
	// System.Int32 TMPro.TMP_LineInfo::lastCharacterIndex
	int32_t ___lastCharacterIndex_7;
	// System.Int32 TMPro.TMP_LineInfo::lastVisibleCharacterIndex
	int32_t ___lastVisibleCharacterIndex_8;
	// System.Single TMPro.TMP_LineInfo::length
	float ___length_9;
	// System.Single TMPro.TMP_LineInfo::lineHeight
	float ___lineHeight_10;
	// System.Single TMPro.TMP_LineInfo::ascender
	float ___ascender_11;
	// System.Single TMPro.TMP_LineInfo::baseline
	float ___baseline_12;
	// System.Single TMPro.TMP_LineInfo::descender
	float ___descender_13;
	// System.Single TMPro.TMP_LineInfo::maxAdvance
	float ___maxAdvance_14;
	// System.Single TMPro.TMP_LineInfo::width
	float ___width_15;
	// System.Single TMPro.TMP_LineInfo::marginLeft
	float ___marginLeft_16;
	// System.Single TMPro.TMP_LineInfo::marginRight
	float ___marginRight_17;
	// TMPro.HorizontalAlignmentOptions TMPro.TMP_LineInfo::alignment
	int32_t ___alignment_18;
	// TMPro.Extents TMPro.TMP_LineInfo::lineExtents
	Extents_tA2D2F95811D0A18CB7AC3570D2D8F8CD3AF4C4A8 ___lineExtents_19;
};

// System.Action`1<System.Boolean>
struct Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C  : public MulticastDelegate_t
{
};

// System.Action`1<UnityEngine.GameObject>
struct Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C  : public MulticastDelegate_t
{
};

// System.Action`1<GameState>
struct Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978  : public MulticastDelegate_t
{
};

// System.Action`1<System.Int32>
struct Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404  : public MulticastDelegate_t
{
};

// System.Action`1<System.String>
struct Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A  : public MulticastDelegate_t
{
};

// System.Action
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07  : public MulticastDelegate_t
{
};

// UnityEngine.AnimationClip
struct AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712  : public Motion_tBCD49FBF5608AD21FC03B63C8182FABCEF2707AC
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// StageDialogue
struct StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	// System.String StageDialogue::_query
	String_t* ____query_4;
	// System.String[] StageDialogue::_comments
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ____comments_5;
	// System.String StageDialogue::_answer
	String_t* ____answer_6;
	// System.String StageDialogue::_compassionateAnswer
	String_t* ____compassionateAnswer_7;
};

// TMPro.TMP_Asset
struct TMP_Asset_t135A047D4F5CBBA9CD356B762B55AB164122B969  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	// System.Int32 TMPro.TMP_Asset::m_InstanceID
	int32_t ___m_InstanceID_4;
	// System.Int32 TMPro.TMP_Asset::hashCode
	int32_t ___hashCode_5;
	// UnityEngine.Material TMPro.TMP_Asset::material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___material_6;
	// System.Int32 TMPro.TMP_Asset::materialHashCode
	int32_t ___materialHashCode_7;
};

// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// TMPro.WordWrapState
struct WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A 
{
	// System.Int32 TMPro.WordWrapState::previous_WordBreak
	int32_t ___previous_WordBreak_0;
	// System.Int32 TMPro.WordWrapState::total_CharacterCount
	int32_t ___total_CharacterCount_1;
	// System.Int32 TMPro.WordWrapState::visible_CharacterCount
	int32_t ___visible_CharacterCount_2;
	// System.Int32 TMPro.WordWrapState::visible_SpriteCount
	int32_t ___visible_SpriteCount_3;
	// System.Int32 TMPro.WordWrapState::visible_LinkCount
	int32_t ___visible_LinkCount_4;
	// System.Int32 TMPro.WordWrapState::firstCharacterIndex
	int32_t ___firstCharacterIndex_5;
	// System.Int32 TMPro.WordWrapState::firstVisibleCharacterIndex
	int32_t ___firstVisibleCharacterIndex_6;
	// System.Int32 TMPro.WordWrapState::lastCharacterIndex
	int32_t ___lastCharacterIndex_7;
	// System.Int32 TMPro.WordWrapState::lastVisibleCharIndex
	int32_t ___lastVisibleCharIndex_8;
	// System.Int32 TMPro.WordWrapState::lineNumber
	int32_t ___lineNumber_9;
	// System.Single TMPro.WordWrapState::maxCapHeight
	float ___maxCapHeight_10;
	// System.Single TMPro.WordWrapState::maxAscender
	float ___maxAscender_11;
	// System.Single TMPro.WordWrapState::maxDescender
	float ___maxDescender_12;
	// System.Single TMPro.WordWrapState::startOfLineAscender
	float ___startOfLineAscender_13;
	// System.Single TMPro.WordWrapState::maxLineAscender
	float ___maxLineAscender_14;
	// System.Single TMPro.WordWrapState::maxLineDescender
	float ___maxLineDescender_15;
	// System.Single TMPro.WordWrapState::pageAscender
	float ___pageAscender_16;
	// TMPro.HorizontalAlignmentOptions TMPro.WordWrapState::horizontalAlignment
	int32_t ___horizontalAlignment_17;
	// System.Single TMPro.WordWrapState::marginLeft
	float ___marginLeft_18;
	// System.Single TMPro.WordWrapState::marginRight
	float ___marginRight_19;
	// System.Single TMPro.WordWrapState::xAdvance
	float ___xAdvance_20;
	// System.Single TMPro.WordWrapState::preferredWidth
	float ___preferredWidth_21;
	// System.Single TMPro.WordWrapState::preferredHeight
	float ___preferredHeight_22;
	// System.Single TMPro.WordWrapState::previousLineScale
	float ___previousLineScale_23;
	// System.Int32 TMPro.WordWrapState::wordCount
	int32_t ___wordCount_24;
	// TMPro.FontStyles TMPro.WordWrapState::fontStyle
	int32_t ___fontStyle_25;
	// System.Int32 TMPro.WordWrapState::italicAngle
	int32_t ___italicAngle_26;
	// System.Single TMPro.WordWrapState::fontScaleMultiplier
	float ___fontScaleMultiplier_27;
	// System.Single TMPro.WordWrapState::currentFontSize
	float ___currentFontSize_28;
	// System.Single TMPro.WordWrapState::baselineOffset
	float ___baselineOffset_29;
	// System.Single TMPro.WordWrapState::lineOffset
	float ___lineOffset_30;
	// System.Boolean TMPro.WordWrapState::isDrivenLineSpacing
	bool ___isDrivenLineSpacing_31;
	// System.Single TMPro.WordWrapState::glyphHorizontalAdvanceAdjustment
	float ___glyphHorizontalAdvanceAdjustment_32;
	// System.Single TMPro.WordWrapState::cSpace
	float ___cSpace_33;
	// System.Single TMPro.WordWrapState::mSpace
	float ___mSpace_34;
	// TMPro.TMP_TextInfo TMPro.WordWrapState::textInfo
	TMP_TextInfo_t09A8E906329422C3F0C059876801DD695B8D524D* ___textInfo_35;
	// TMPro.TMP_LineInfo TMPro.WordWrapState::lineInfo
	TMP_LineInfo_tB75C1965B58DB7B3A046C8CA55AD6AB92B6B17B3 ___lineInfo_36;
	// UnityEngine.Color32 TMPro.WordWrapState::vertexColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___vertexColor_37;
	// UnityEngine.Color32 TMPro.WordWrapState::underlineColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___underlineColor_38;
	// UnityEngine.Color32 TMPro.WordWrapState::strikethroughColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___strikethroughColor_39;
	// UnityEngine.Color32 TMPro.WordWrapState::highlightColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___highlightColor_40;
	// TMPro.TMP_FontStyleStack TMPro.WordWrapState::basicStyleStack
	TMP_FontStyleStack_t52885F172FADBC21346C835B5302167BDA8020DC ___basicStyleStack_41;
	// TMPro.TMP_TextProcessingStack`1<System.Int32> TMPro.WordWrapState::italicAngleStack
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___italicAngleStack_42;
	// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32> TMPro.WordWrapState::colorStack
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___colorStack_43;
	// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32> TMPro.WordWrapState::underlineColorStack
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___underlineColorStack_44;
	// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32> TMPro.WordWrapState::strikethroughColorStack
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___strikethroughColorStack_45;
	// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32> TMPro.WordWrapState::highlightColorStack
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___highlightColorStack_46;
	// TMPro.TMP_TextProcessingStack`1<TMPro.HighlightState> TMPro.WordWrapState::highlightStateStack
	TMP_TextProcessingStack_1_t57AECDCC936A7FF1D6CF66CA11560B28A675648D ___highlightStateStack_47;
	// TMPro.TMP_TextProcessingStack`1<TMPro.TMP_ColorGradient> TMPro.WordWrapState::colorGradientStack
	TMP_TextProcessingStack_1_tC8FAEB17246D3B171EFD11165A5761AE39B40D0C ___colorGradientStack_48;
	// TMPro.TMP_TextProcessingStack`1<System.Single> TMPro.WordWrapState::sizeStack
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___sizeStack_49;
	// TMPro.TMP_TextProcessingStack`1<System.Single> TMPro.WordWrapState::indentStack
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___indentStack_50;
	// TMPro.TMP_TextProcessingStack`1<TMPro.FontWeight> TMPro.WordWrapState::fontWeightStack
	TMP_TextProcessingStack_1_tA5C8CED87DD9E73F6359E23B334FFB5B6F813FD4 ___fontWeightStack_51;
	// TMPro.TMP_TextProcessingStack`1<System.Int32> TMPro.WordWrapState::styleStack
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___styleStack_52;
	// TMPro.TMP_TextProcessingStack`1<System.Single> TMPro.WordWrapState::baselineStack
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___baselineStack_53;
	// TMPro.TMP_TextProcessingStack`1<System.Int32> TMPro.WordWrapState::actionStack
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___actionStack_54;
	// TMPro.TMP_TextProcessingStack`1<TMPro.MaterialReference> TMPro.WordWrapState::materialReferenceStack
	TMP_TextProcessingStack_1_tB03E08F69415B281A5A81138F09E49EE58402DF9 ___materialReferenceStack_55;
	// TMPro.TMP_TextProcessingStack`1<TMPro.HorizontalAlignmentOptions> TMPro.WordWrapState::lineJustificationStack
	TMP_TextProcessingStack_1_t243EA1B5D7FD2295D6533B953F0BBE8F52EFB8A0 ___lineJustificationStack_56;
	// System.Int32 TMPro.WordWrapState::spriteAnimationID
	int32_t ___spriteAnimationID_57;
	// TMPro.TMP_FontAsset TMPro.WordWrapState::currentFontAsset
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___currentFontAsset_58;
	// TMPro.TMP_SpriteAsset TMPro.WordWrapState::currentSpriteAsset
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___currentSpriteAsset_59;
	// UnityEngine.Material TMPro.WordWrapState::currentMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___currentMaterial_60;
	// System.Int32 TMPro.WordWrapState::currentMaterialIndex
	int32_t ___currentMaterialIndex_61;
	// TMPro.Extents TMPro.WordWrapState::meshExtents
	Extents_tA2D2F95811D0A18CB7AC3570D2D8F8CD3AF4C4A8 ___meshExtents_62;
	// System.Boolean TMPro.WordWrapState::tagNoParsing
	bool ___tagNoParsing_63;
	// System.Boolean TMPro.WordWrapState::isNonBreakingSpace
	bool ___isNonBreakingSpace_64;
};
// Native definition for P/Invoke marshalling of TMPro.WordWrapState
struct WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A_marshaled_pinvoke
{
	int32_t ___previous_WordBreak_0;
	int32_t ___total_CharacterCount_1;
	int32_t ___visible_CharacterCount_2;
	int32_t ___visible_SpriteCount_3;
	int32_t ___visible_LinkCount_4;
	int32_t ___firstCharacterIndex_5;
	int32_t ___firstVisibleCharacterIndex_6;
	int32_t ___lastCharacterIndex_7;
	int32_t ___lastVisibleCharIndex_8;
	int32_t ___lineNumber_9;
	float ___maxCapHeight_10;
	float ___maxAscender_11;
	float ___maxDescender_12;
	float ___startOfLineAscender_13;
	float ___maxLineAscender_14;
	float ___maxLineDescender_15;
	float ___pageAscender_16;
	int32_t ___horizontalAlignment_17;
	float ___marginLeft_18;
	float ___marginRight_19;
	float ___xAdvance_20;
	float ___preferredWidth_21;
	float ___preferredHeight_22;
	float ___previousLineScale_23;
	int32_t ___wordCount_24;
	int32_t ___fontStyle_25;
	int32_t ___italicAngle_26;
	float ___fontScaleMultiplier_27;
	float ___currentFontSize_28;
	float ___baselineOffset_29;
	float ___lineOffset_30;
	int32_t ___isDrivenLineSpacing_31;
	float ___glyphHorizontalAdvanceAdjustment_32;
	float ___cSpace_33;
	float ___mSpace_34;
	TMP_TextInfo_t09A8E906329422C3F0C059876801DD695B8D524D* ___textInfo_35;
	TMP_LineInfo_tB75C1965B58DB7B3A046C8CA55AD6AB92B6B17B3 ___lineInfo_36;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___vertexColor_37;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___underlineColor_38;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___strikethroughColor_39;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___highlightColor_40;
	TMP_FontStyleStack_t52885F172FADBC21346C835B5302167BDA8020DC ___basicStyleStack_41;
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___italicAngleStack_42;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___colorStack_43;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___underlineColorStack_44;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___strikethroughColorStack_45;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___highlightColorStack_46;
	TMP_TextProcessingStack_1_t57AECDCC936A7FF1D6CF66CA11560B28A675648D ___highlightStateStack_47;
	TMP_TextProcessingStack_1_tC8FAEB17246D3B171EFD11165A5761AE39B40D0C ___colorGradientStack_48;
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___sizeStack_49;
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___indentStack_50;
	TMP_TextProcessingStack_1_tA5C8CED87DD9E73F6359E23B334FFB5B6F813FD4 ___fontWeightStack_51;
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___styleStack_52;
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___baselineStack_53;
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___actionStack_54;
	TMP_TextProcessingStack_1_tB03E08F69415B281A5A81138F09E49EE58402DF9 ___materialReferenceStack_55;
	TMP_TextProcessingStack_1_t243EA1B5D7FD2295D6533B953F0BBE8F52EFB8A0 ___lineJustificationStack_56;
	int32_t ___spriteAnimationID_57;
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___currentFontAsset_58;
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___currentSpriteAsset_59;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___currentMaterial_60;
	int32_t ___currentMaterialIndex_61;
	Extents_tA2D2F95811D0A18CB7AC3570D2D8F8CD3AF4C4A8 ___meshExtents_62;
	int32_t ___tagNoParsing_63;
	int32_t ___isNonBreakingSpace_64;
};
// Native definition for COM marshalling of TMPro.WordWrapState
struct WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A_marshaled_com
{
	int32_t ___previous_WordBreak_0;
	int32_t ___total_CharacterCount_1;
	int32_t ___visible_CharacterCount_2;
	int32_t ___visible_SpriteCount_3;
	int32_t ___visible_LinkCount_4;
	int32_t ___firstCharacterIndex_5;
	int32_t ___firstVisibleCharacterIndex_6;
	int32_t ___lastCharacterIndex_7;
	int32_t ___lastVisibleCharIndex_8;
	int32_t ___lineNumber_9;
	float ___maxCapHeight_10;
	float ___maxAscender_11;
	float ___maxDescender_12;
	float ___startOfLineAscender_13;
	float ___maxLineAscender_14;
	float ___maxLineDescender_15;
	float ___pageAscender_16;
	int32_t ___horizontalAlignment_17;
	float ___marginLeft_18;
	float ___marginRight_19;
	float ___xAdvance_20;
	float ___preferredWidth_21;
	float ___preferredHeight_22;
	float ___previousLineScale_23;
	int32_t ___wordCount_24;
	int32_t ___fontStyle_25;
	int32_t ___italicAngle_26;
	float ___fontScaleMultiplier_27;
	float ___currentFontSize_28;
	float ___baselineOffset_29;
	float ___lineOffset_30;
	int32_t ___isDrivenLineSpacing_31;
	float ___glyphHorizontalAdvanceAdjustment_32;
	float ___cSpace_33;
	float ___mSpace_34;
	TMP_TextInfo_t09A8E906329422C3F0C059876801DD695B8D524D* ___textInfo_35;
	TMP_LineInfo_tB75C1965B58DB7B3A046C8CA55AD6AB92B6B17B3 ___lineInfo_36;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___vertexColor_37;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___underlineColor_38;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___strikethroughColor_39;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___highlightColor_40;
	TMP_FontStyleStack_t52885F172FADBC21346C835B5302167BDA8020DC ___basicStyleStack_41;
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___italicAngleStack_42;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___colorStack_43;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___underlineColorStack_44;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___strikethroughColorStack_45;
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___highlightColorStack_46;
	TMP_TextProcessingStack_1_t57AECDCC936A7FF1D6CF66CA11560B28A675648D ___highlightStateStack_47;
	TMP_TextProcessingStack_1_tC8FAEB17246D3B171EFD11165A5761AE39B40D0C ___colorGradientStack_48;
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___sizeStack_49;
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___indentStack_50;
	TMP_TextProcessingStack_1_tA5C8CED87DD9E73F6359E23B334FFB5B6F813FD4 ___fontWeightStack_51;
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___styleStack_52;
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___baselineStack_53;
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___actionStack_54;
	TMP_TextProcessingStack_1_tB03E08F69415B281A5A81138F09E49EE58402DF9 ___materialReferenceStack_55;
	TMP_TextProcessingStack_1_t243EA1B5D7FD2295D6533B953F0BBE8F52EFB8A0 ___lineJustificationStack_56;
	int32_t ___spriteAnimationID_57;
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___currentFontAsset_58;
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___currentSpriteAsset_59;
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___currentMaterial_60;
	int32_t ___currentMaterialIndex_61;
	Extents_tA2D2F95811D0A18CB7AC3570D2D8F8CD3AF4C4A8 ___meshExtents_62;
	int32_t ___tagNoParsing_63;
	int32_t ___isNonBreakingSpace_64;
};

// TMPro.TMP_TextProcessingStack`1<TMPro.WordWrapState>
struct TMP_TextProcessingStack_1_t2DDA00FFC64AF6E3AFD475AB2086D16C34787E0F 
{
	// T[] TMPro.TMP_TextProcessingStack`1::itemStack
	WordWrapStateU5BU5D_t473D59C9DBCC949CE72EF1EB471CBA152A6CEAC9* ___itemStack_0;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::index
	int32_t ___index_1;
	// T TMPro.TMP_TextProcessingStack`1::m_DefaultItem
	WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A ___m_DefaultItem_2;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Capacity
	int32_t ___m_Capacity_3;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_RolloverSize
	int32_t ___m_RolloverSize_4;
	// System.Int32 TMPro.TMP_TextProcessingStack`1::m_Count
	int32_t ___m_Count_5;
};

// UnityEngine.Animation
struct Animation_t6593B06C39E3B139808B19F2C719C860F3F61040  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.AudioBehaviour
struct AudioBehaviour_t2DC0BEF7B020C952F3D2DA5AAAC88501C7EEB941  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// TMPro.TMP_FontAsset
struct TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160  : public TMP_Asset_t135A047D4F5CBBA9CD356B762B55AB164122B969
{
	// System.String TMPro.TMP_FontAsset::m_Version
	String_t* ___m_Version_8;
	// System.String TMPro.TMP_FontAsset::m_SourceFontFileGUID
	String_t* ___m_SourceFontFileGUID_9;
	// UnityEngine.Font TMPro.TMP_FontAsset::m_SourceFontFile
	Font_tC95270EA3198038970422D78B74A7F2E218A96B6* ___m_SourceFontFile_10;
	// TMPro.AtlasPopulationMode TMPro.TMP_FontAsset::m_AtlasPopulationMode
	int32_t ___m_AtlasPopulationMode_11;
	// UnityEngine.TextCore.FaceInfo TMPro.TMP_FontAsset::m_FaceInfo
	FaceInfo_t12F0319E555A62CBA1D9E51A16C7963393932756 ___m_FaceInfo_12;
	// System.Collections.Generic.List`1<UnityEngine.TextCore.Glyph> TMPro.TMP_FontAsset::m_GlyphTable
	List_1_t95DB74B8EE315F8F92B7B96D93C901C8C3F6FE2C* ___m_GlyphTable_13;
	// System.Collections.Generic.Dictionary`2<System.UInt32,UnityEngine.TextCore.Glyph> TMPro.TMP_FontAsset::m_GlyphLookupDictionary
	Dictionary_2_tC61348D10610A6B3D7B65102D82AC3467D59EAA7* ___m_GlyphLookupDictionary_14;
	// System.Collections.Generic.List`1<TMPro.TMP_Character> TMPro.TMP_FontAsset::m_CharacterTable
	List_1_tCE1ACAA0C2736A7797B2C134895298CAB10BEB5E* ___m_CharacterTable_15;
	// System.Collections.Generic.Dictionary`2<System.UInt32,TMPro.TMP_Character> TMPro.TMP_FontAsset::m_CharacterLookupDictionary
	Dictionary_2_tCB5FEF8D6CEA1557D9B9BA25946AD6BF3E6C14D0* ___m_CharacterLookupDictionary_16;
	// UnityEngine.Texture2D TMPro.TMP_FontAsset::m_AtlasTexture
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___m_AtlasTexture_17;
	// UnityEngine.Texture2D[] TMPro.TMP_FontAsset::m_AtlasTextures
	Texture2DU5BU5D_t05332F1E3F7D4493E304C702201F9BE4F9236191* ___m_AtlasTextures_18;
	// System.Int32 TMPro.TMP_FontAsset::m_AtlasTextureIndex
	int32_t ___m_AtlasTextureIndex_19;
	// System.Boolean TMPro.TMP_FontAsset::m_IsMultiAtlasTexturesEnabled
	bool ___m_IsMultiAtlasTexturesEnabled_20;
	// System.Boolean TMPro.TMP_FontAsset::m_ClearDynamicDataOnBuild
	bool ___m_ClearDynamicDataOnBuild_21;
	// System.Collections.Generic.List`1<UnityEngine.TextCore.GlyphRect> TMPro.TMP_FontAsset::m_UsedGlyphRects
	List_1_t425D3A455811E316D2DF73E46CF9CD90A4341C1B* ___m_UsedGlyphRects_22;
	// System.Collections.Generic.List`1<UnityEngine.TextCore.GlyphRect> TMPro.TMP_FontAsset::m_FreeGlyphRects
	List_1_t425D3A455811E316D2DF73E46CF9CD90A4341C1B* ___m_FreeGlyphRects_23;
	// TMPro.FaceInfo_Legacy TMPro.TMP_FontAsset::m_fontInfo
	FaceInfo_Legacy_t23B118EFD5AB7162515ABF18C0212DF155CCF7B8* ___m_fontInfo_24;
	// UnityEngine.Texture2D TMPro.TMP_FontAsset::atlas
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___atlas_25;
	// System.Int32 TMPro.TMP_FontAsset::m_AtlasWidth
	int32_t ___m_AtlasWidth_26;
	// System.Int32 TMPro.TMP_FontAsset::m_AtlasHeight
	int32_t ___m_AtlasHeight_27;
	// System.Int32 TMPro.TMP_FontAsset::m_AtlasPadding
	int32_t ___m_AtlasPadding_28;
	// UnityEngine.TextCore.LowLevel.GlyphRenderMode TMPro.TMP_FontAsset::m_AtlasRenderMode
	int32_t ___m_AtlasRenderMode_29;
	// System.Collections.Generic.List`1<TMPro.TMP_Glyph> TMPro.TMP_FontAsset::m_glyphInfoList
	List_1_tAB7976FADCF872E418770E60783056C23394843D* ___m_glyphInfoList_30;
	// TMPro.KerningTable TMPro.TMP_FontAsset::m_KerningTable
	KerningTable_t040C3FE3B519B12AADE1C5B00628581551D5AB6B* ___m_KerningTable_31;
	// TMPro.TMP_FontFeatureTable TMPro.TMP_FontAsset::m_FontFeatureTable
	TMP_FontFeatureTable_t726A09E64FDF682A8FFE294BB6CFE7747F6C40EA* ___m_FontFeatureTable_32;
	// System.Collections.Generic.List`1<TMPro.TMP_FontAsset> TMPro.TMP_FontAsset::fallbackFontAssets
	List_1_t06C3ABB0C6F2347B32881E33D154431EADAE3ECF* ___fallbackFontAssets_33;
	// System.Collections.Generic.List`1<TMPro.TMP_FontAsset> TMPro.TMP_FontAsset::m_FallbackFontAssetTable
	List_1_t06C3ABB0C6F2347B32881E33D154431EADAE3ECF* ___m_FallbackFontAssetTable_34;
	// TMPro.FontAssetCreationSettings TMPro.TMP_FontAsset::m_CreationSettings
	FontAssetCreationSettings_t2B94078737A72F814E8BC2126F967B94231190DF ___m_CreationSettings_35;
	// TMPro.TMP_FontWeightPair[] TMPro.TMP_FontAsset::m_FontWeightTable
	TMP_FontWeightPairU5BU5D_t0A3A5955F13FEB2F7329D81BA157110DB99F9F37* ___m_FontWeightTable_36;
	// TMPro.TMP_FontWeightPair[] TMPro.TMP_FontAsset::fontWeights
	TMP_FontWeightPairU5BU5D_t0A3A5955F13FEB2F7329D81BA157110DB99F9F37* ___fontWeights_37;
	// System.Single TMPro.TMP_FontAsset::normalStyle
	float ___normalStyle_38;
	// System.Single TMPro.TMP_FontAsset::normalSpacingOffset
	float ___normalSpacingOffset_39;
	// System.Single TMPro.TMP_FontAsset::boldStyle
	float ___boldStyle_40;
	// System.Single TMPro.TMP_FontAsset::boldSpacing
	float ___boldSpacing_41;
	// System.Byte TMPro.TMP_FontAsset::italicStyle
	uint8_t ___italicStyle_42;
	// System.Byte TMPro.TMP_FontAsset::tabSize
	uint8_t ___tabSize_43;
	// System.Boolean TMPro.TMP_FontAsset::IsFontAssetLookupTablesDirty
	bool ___IsFontAssetLookupTablesDirty_44;
	// System.Collections.Generic.HashSet`1<System.Int32> TMPro.TMP_FontAsset::FallbackSearchQueryLookup
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___FallbackSearchQueryLookup_53;
	// System.Collections.Generic.List`1<UnityEngine.TextCore.Glyph> TMPro.TMP_FontAsset::m_GlyphsToRender
	List_1_t95DB74B8EE315F8F92B7B96D93C901C8C3F6FE2C* ___m_GlyphsToRender_59;
	// System.Collections.Generic.List`1<UnityEngine.TextCore.Glyph> TMPro.TMP_FontAsset::m_GlyphsRendered
	List_1_t95DB74B8EE315F8F92B7B96D93C901C8C3F6FE2C* ___m_GlyphsRendered_60;
	// System.Collections.Generic.List`1<System.UInt32> TMPro.TMP_FontAsset::m_GlyphIndexList
	List_1_t9B68833848E4C4D7F623C05F6B77F0449396354A* ___m_GlyphIndexList_61;
	// System.Collections.Generic.List`1<System.UInt32> TMPro.TMP_FontAsset::m_GlyphIndexListNewlyAdded
	List_1_t9B68833848E4C4D7F623C05F6B77F0449396354A* ___m_GlyphIndexListNewlyAdded_62;
	// System.Collections.Generic.List`1<System.UInt32> TMPro.TMP_FontAsset::m_GlyphsToAdd
	List_1_t9B68833848E4C4D7F623C05F6B77F0449396354A* ___m_GlyphsToAdd_63;
	// System.Collections.Generic.HashSet`1<System.UInt32> TMPro.TMP_FontAsset::m_GlyphsToAddLookup
	HashSet_1_t5DD20B42149A11AEBF12A75505306E6EFC34943A* ___m_GlyphsToAddLookup_64;
	// System.Collections.Generic.List`1<TMPro.TMP_Character> TMPro.TMP_FontAsset::m_CharactersToAdd
	List_1_tCE1ACAA0C2736A7797B2C134895298CAB10BEB5E* ___m_CharactersToAdd_65;
	// System.Collections.Generic.HashSet`1<System.UInt32> TMPro.TMP_FontAsset::m_CharactersToAddLookup
	HashSet_1_t5DD20B42149A11AEBF12A75505306E6EFC34943A* ___m_CharactersToAddLookup_66;
	// System.Collections.Generic.List`1<System.UInt32> TMPro.TMP_FontAsset::s_MissingCharacterList
	List_1_t9B68833848E4C4D7F623C05F6B77F0449396354A* ___s_MissingCharacterList_67;
	// System.Collections.Generic.HashSet`1<System.UInt32> TMPro.TMP_FontAsset::m_MissingUnicodesFromFontFile
	HashSet_1_t5DD20B42149A11AEBF12A75505306E6EFC34943A* ___m_MissingUnicodesFromFontFile_68;
};

// AudioManager
struct AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Single AudioManager::_missileVol
	float ____missileVol_4;
	// System.Single AudioManager::_starGainVol
	float ____starGainVol_5;
	// System.Single AudioManager::_UIClickVol
	float ____UIClickVol_6;
	// System.Single AudioManager::_UIZapVol
	float ____UIZapVol_7;
	// System.Single AudioManager::_UIstarVol
	float ____UIstarVol_8;
	// System.Single AudioManager::_UIlevelDoneVol
	float ____UIlevelDoneVol_9;
	// System.Single AudioManager::_musicVol
	float ____musicVol_10;
	// System.Single AudioManager::_powerUpVol
	float ____powerUpVol_11;
	// System.Single AudioManager::_compassionateVol
	float ____compassionateVol_12;
	// System.Single AudioManager::_negativeVol
	float ____negativeVol_13;
	// System.Single[] AudioManager::_beepVol
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ____beepVol_14;
	// UnityEngine.AudioSource AudioManager::MissileBeep
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___MissileBeep_15;
	// UnityEngine.AudioSource AudioManager::Negative
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___Negative_16;
	// UnityEngine.AudioSource AudioManager::StarGain
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___StarGain_17;
	// UnityEngine.AudioSource AudioManager::UIClick
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___UIClick_18;
	// UnityEngine.AudioSource AudioManager::UIZap
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___UIZap_19;
	// UnityEngine.AudioSource AudioManager::UIStar
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___UIStar_20;
	// UnityEngine.AudioSource AudioManager::UILevelDone
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___UILevelDone_21;
	// UnityEngine.AudioSource AudioManager::Music
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___Music_22;
	// UnityEngine.AudioSource AudioManager::PowerUp
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___PowerUp_23;
	// UnityEngine.AudioSource AudioManager::CompassionateVictory
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___CompassionateVictory_24;
	// UnityEngine.AudioSource[] AudioManager::CrystalPop
	AudioSourceU5BU5D_tBBF6E920E0DC80D53D4BB2A8D4C80D244EF170B2* ___CrystalPop_25;
};

// UnityEngine.AudioSource
struct AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299  : public AudioBehaviour_t2DC0BEF7B020C952F3D2DA5AAAC88501C7EEB941
{
};

// ButtonToggle
struct ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// ButtonToggle/ButtonType ButtonToggle::_buttonType
	int32_t ____buttonType_4;
	// UnityEngine.UI.Image ButtonToggle::_enabledImage
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ____enabledImage_5;
	// UnityEngine.UI.Image ButtonToggle::_disabledImage
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ____disabledImage_6;
	// System.Boolean ButtonToggle::_isEnabled
	bool ____isEnabled_7;
};

// DialogueManager
struct DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Collections.Generic.Queue`1<System.String> DialogueManager::_currentDialogue
	Queue_1_t55768C6731D974992BF9775CEA33AAFE7F51CF31* ____currentDialogue_4;
	// System.Boolean DialogueManager::_isDialogueActive
	bool ____isDialogueActive_5;
	// System.Boolean DialogueManager::_isTutorialDialogueActive
	bool ____isTutorialDialogueActive_6;
	// System.Boolean DialogueManager::_isQuery
	bool ____isQuery_7;
};

// GameManager
struct GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Boolean GameManager::_debugMode
	bool ____debugMode_4;
	// System.Int32 GameManager::_debugStartStage
	int32_t ____debugStartStage_5;
	// GM_Settings GameManager::_settings
	GM_Settings_tACC8EDD99D4AE7595B5800679E91C7092AC6157C* ____settings_6;
	// UnityEngine.GameObject GameManager::_runnerPrefab
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____runnerPrefab_7;
	// System.Int32 GameManager::_firstPurpleStage
	int32_t ____firstPurpleStage_8;
	// System.Int32 GameManager::_firstGoldStage
	int32_t ____firstGoldStage_9;
	// UnityEngine.Transform GameManager::SampleTileTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___SampleTileTransform_10;
	// Dialogue[] GameManager::_allTutorialDialogue
	DialogueU5BU5D_tDFA7242FC4BAE908FF3783F71719173C548502BB* ____allTutorialDialogue_11;
	// StageDialogue[] GameManager::_globalStageDialogue
	StageDialogueU5BU5D_t9A4B8E88A6CF81BAF244E49D4CBDF2AB4D9C2B06* ____globalStageDialogue_12;
	// UnityEngine.AnimationCurve GameManager::_tileSpeedCurve
	AnimationCurve_tCBFFAAD05CEBB35EF8D8631BD99914BE1A6BB354* ____tileSpeedCurve_14;
	// UnityEngine.AnimationCurve GameManager::_runnerSpeedCurve
	AnimationCurve_tCBFFAAD05CEBB35EF8D8631BD99914BE1A6BB354* ____runnerSpeedCurve_15;
	// UnityEngine.AnimationCurve GameManager::_runnerTransitionCurve
	AnimationCurve_tCBFFAAD05CEBB35EF8D8631BD99914BE1A6BB354* ____runnerTransitionCurve_16;
	// UnityEngine.AnimationCurve GameManager::_tileSpawnerWidthCurve
	AnimationCurve_tCBFFAAD05CEBB35EF8D8631BD99914BE1A6BB354* ____tileSpawnerWidthCurve_17;
	// UnityEngine.GameObject GameManager::_currentRunner
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____currentRunner_18;
	// System.Single GameManager::_defaultSpeed
	float ____defaultSpeed_19;
	// System.Int32 GameManager::_starBonus
	int32_t ____starBonus_20;
	// System.Int32 GameManager::_compassionateStars
	int32_t ____compassionateStars_21;
	// System.Int32 GameManager::_compassionateProgress
	int32_t ____compassionateProgress_22;
	// UnityEngine.WaitForSeconds GameManager::_bonusDelay
	WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* ____bonusDelay_23;
	// UnityEngine.WaitForSeconds GameManager::_bonusStep
	WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* ____bonusStep_24;
	// UnityEngine.WaitForSeconds GameManager::_runnerTeleportDelay
	WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* ____runnerTeleportDelay_25;
	// System.Boolean GameManager::_startOfGame
	bool ____startOfGame_26;
	// System.Boolean GameManager::_decreaseSpeedBonus
	bool ____decreaseSpeedBonus_27;
	// System.Boolean GameManager::_triggerBonusStep
	bool ____triggerBonusStep_28;
};

// UnityEngine.EventSystems.UIBehaviour
struct UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// UIManager
struct UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// TMPro.TextMeshProUGUI UIManager::_topTotalStarAmount
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* ____topTotalStarAmount_4;
	// TMPro.TextMeshProUGUI UIManager::_stageCurrentScore
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* ____stageCurrentScore_5;
	// TMPro.TextMeshProUGUI UIManager::_stageAssessment
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* ____stageAssessment_6;
	// TMPro.TextMeshProUGUI UIManager::_lifetimeStarsAmountMenu
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* ____lifetimeStarsAmountMenu_7;
	// TMPro.TextMeshProUGUI UIManager::_newHighScore
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* ____newHighScore_8;
	// UnityEngine.UI.Slider[] UIManager::_speedSliders
	SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* ____speedSliders_9;
	// UnityEngine.GameObject UIManager::_requiredStars
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____requiredStars_10;
	// UnityEngine.GameObject UIManager::_starParent
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____starParent_11;
	// UnityEngine.GameObject UIManager::_compassionateStars
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____compassionateStars_12;
	// UnityEngine.UI.Slider[] UIManager::_compassionateSliders
	SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* ____compassionateSliders_13;
	// UnityEngine.Canvas UIManager::_stageCanvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ____stageCanvas_14;
	// UnityEngine.Canvas UIManager::_topCanvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ____topCanvas_15;
	// UnityEngine.Canvas UIManager::_mainMenuCanvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ____mainMenuCanvas_16;
	// UnityEngine.Canvas UIManager::_menuSettingsCanvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ____menuSettingsCanvas_17;
	// UnityEngine.GameObject UIManager::_starPrefab
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____starPrefab_18;
	// UnityEngine.GameObject UIManager::_mainMenuButtons
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____mainMenuButtons_19;
	// UnityEngine.GameObject UIManager::_endStageButtons
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____endStageButtons_20;
	// UnityEngine.GameObject UIManager::_mainPage
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____mainPage_21;
	// UnityEngine.GameObject UIManager::_backPage
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____backPage_22;
	// UnityEngine.UI.Button UIManager::_storyModeButton
	Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* ____storyModeButton_23;
	// UnityEngine.UI.Button UIManager::_challengeModeButton
	Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* ____challengeModeButton_24;
	// UnityEngine.UI.Button UIManager::_quitButton
	Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* ____quitButton_25;
	// UnityEngine.UI.Button UIManager::_quitToMenuButton
	Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* ____quitToMenuButton_26;
	// UnityEngine.UI.Button UIManager::_resetButton
	Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* ____resetButton_27;
	// TMPro.TextMeshProUGUI UIManager::_loadingText
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* ____loadingText_28;
	// UnityEngine.UI.Image UIManager::_blackScreenStart
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ____blackScreenStart_29;
	// UnityEngine.UI.Image UIManager::_blackScreenEnd
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ____blackScreenEnd_30;
	// UnityEngine.GameObject UIManager::_endCreditsObj
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ____endCreditsObj_31;
	// UnityEngine.Animation UIManager::_blackScreenFadeOut
	Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* ____blackScreenFadeOut_32;
	// UnityEngine.Animation UIManager::_blackScreenFadeIn
	Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* ____blackScreenFadeIn_33;
	// UnityEngine.Animation UIManager::_endCreditsAnimation
	Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* ____endCreditsAnimation_34;
	// TMPro.TMP_FontAsset UIManager::_liberationFont
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ____liberationFont_35;
	// TMPro.TMP_FontAsset UIManager::_VCRFont
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ____VCRFont_36;
	// UnityEngine.WaitForSecondsRealtime UIManager::_sentenceDelay
	WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* ____sentenceDelay_37;
	// UnityEngine.WaitForSecondsRealtime UIManager::_starGainDelay
	WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* ____starGainDelay_38;
	// System.Boolean UIManager::_typeOutSentence
	bool ____typeOutSentence_39;
	// System.Boolean UIManager::_isDialogueBoxOpen
	bool ____isDialogueBoxOpen_40;
	// TMPro.TextMeshProUGUI UIManager::_dialogueBox
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* ____dialogueBox_41;
	// UnityEngine.UI.Image UIManager::_runnerFace
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ____runnerFace_42;
	// System.Int32 UIManager::_newStarIndex
	int32_t ____newStarIndex_43;
	// System.Int32 UIManager::_bonusStarIndex
	int32_t ____bonusStarIndex_44;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> UIManager::_allStars
	List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* ____allStars_45;
	// UnityEngine.UI.Slider UIManager::_activeSlider
	Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* ____activeSlider_46;
	// UnityEngine.WaitForSecondsRealtime UIManager::_hintDelay
	WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* ____hintDelay_47;
	// UnityEngine.WaitForSeconds UIManager::_menuResetDelay
	WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* ____menuResetDelay_48;
	// UnityEngine.Color UIManager::_runnerDialogueColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ____runnerDialogueColor_49;
	// UnityEngine.Color UIManager::_incomingQueryColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ____incomingQueryColor_50;
	// System.String UIManager::_currentSentence
	String_t* ____currentSentence_51;
	// System.Boolean UIManager::_blackScreenEndDeactivated
	bool ____blackScreenEndDeactivated_52;
};

// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// UnityEngine.Material UnityEngine.UI.Graphic::m_Material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_Material_6;
	// UnityEngine.Color UnityEngine.UI.Graphic::m_Color
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_Color_7;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipLayoutUpdate
	bool ___m_SkipLayoutUpdate_8;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipMaterialUpdate
	bool ___m_SkipMaterialUpdate_9;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTarget
	bool ___m_RaycastTarget_10;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTargetCache
	bool ___m_RaycastTargetCache_11;
	// UnityEngine.Vector4 UnityEngine.UI.Graphic::m_RaycastPadding
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_RaycastPadding_12;
	// UnityEngine.RectTransform UnityEngine.UI.Graphic::m_RectTransform
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_RectTransform_13;
	// UnityEngine.CanvasRenderer UnityEngine.UI.Graphic::m_CanvasRenderer
	CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860* ___m_CanvasRenderer_14;
	// UnityEngine.Canvas UnityEngine.UI.Graphic::m_Canvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ___m_Canvas_15;
	// System.Boolean UnityEngine.UI.Graphic::m_VertsDirty
	bool ___m_VertsDirty_16;
	// System.Boolean UnityEngine.UI.Graphic::m_MaterialDirty
	bool ___m_MaterialDirty_17;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyLayoutCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyLayoutCallback_18;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyVertsCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyVertsCallback_19;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyMaterialCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyMaterialCallback_20;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::m_CachedMesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___m_CachedMesh_23;
	// UnityEngine.Vector2[] UnityEngine.UI.Graphic::m_CachedUvs
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___m_CachedUvs_24;
	// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween> UnityEngine.UI.Graphic::m_ColorTweenRunner
	TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4* ___m_ColorTweenRunner_25;
	// System.Boolean UnityEngine.UI.Graphic::<useLegacyMeshGeneration>k__BackingField
	bool ___U3CuseLegacyMeshGenerationU3Ek__BackingField_26;
};

// UnityEngine.UI.Selectable
struct Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// System.Boolean UnityEngine.UI.Selectable::m_EnableCalled
	bool ___m_EnableCalled_6;
	// UnityEngine.UI.Navigation UnityEngine.UI.Selectable::m_Navigation
	Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C ___m_Navigation_7;
	// UnityEngine.UI.Selectable/Transition UnityEngine.UI.Selectable::m_Transition
	int32_t ___m_Transition_8;
	// UnityEngine.UI.ColorBlock UnityEngine.UI.Selectable::m_Colors
	ColorBlock_tDD7C62E7AFE442652FC98F8D058CE8AE6BFD7C11 ___m_Colors_9;
	// UnityEngine.UI.SpriteState UnityEngine.UI.Selectable::m_SpriteState
	SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD ___m_SpriteState_10;
	// UnityEngine.UI.AnimationTriggers UnityEngine.UI.Selectable::m_AnimationTriggers
	AnimationTriggers_tA0DC06F89C5280C6DD972F6F4C8A56D7F4F79074* ___m_AnimationTriggers_11;
	// System.Boolean UnityEngine.UI.Selectable::m_Interactable
	bool ___m_Interactable_12;
	// UnityEngine.UI.Graphic UnityEngine.UI.Selectable::m_TargetGraphic
	Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931* ___m_TargetGraphic_13;
	// System.Boolean UnityEngine.UI.Selectable::m_GroupsAllowInteraction
	bool ___m_GroupsAllowInteraction_14;
	// System.Int32 UnityEngine.UI.Selectable::m_CurrentIndex
	int32_t ___m_CurrentIndex_15;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerInside>k__BackingField
	bool ___U3CisPointerInsideU3Ek__BackingField_16;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerDown>k__BackingField
	bool ___U3CisPointerDownU3Ek__BackingField_17;
	// System.Boolean UnityEngine.UI.Selectable::<hasSelection>k__BackingField
	bool ___U3ChasSelectionU3Ek__BackingField_18;
	// System.Collections.Generic.List`1<UnityEngine.CanvasGroup> UnityEngine.UI.Selectable::m_CanvasGroupCache
	List_1_t2CDCA768E7F493F5EDEBC75AEB200FD621354E35* ___m_CanvasGroupCache_19;
};

// UnityEngine.UI.Button
struct Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098  : public Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712
{
	// UnityEngine.UI.Button/ButtonClickedEvent UnityEngine.UI.Button::m_OnClick
	ButtonClickedEvent_t8EA72E90B3BD1392FB3B3EF167D5121C23569E4C* ___m_OnClick_20;
};

// UnityEngine.UI.MaskableGraphic
struct MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E  : public Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931
{
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculateStencil
	bool ___m_ShouldRecalculateStencil_27;
	// UnityEngine.Material UnityEngine.UI.MaskableGraphic::m_MaskMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_MaskMaterial_28;
	// UnityEngine.UI.RectMask2D UnityEngine.UI.MaskableGraphic::m_ParentMask
	RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670* ___m_ParentMask_29;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_Maskable
	bool ___m_Maskable_30;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IsMaskingGraphic
	bool ___m_IsMaskingGraphic_31;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IncludeForMasking
	bool ___m_IncludeForMasking_32;
	// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent UnityEngine.UI.MaskableGraphic::m_OnCullStateChanged
	CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8* ___m_OnCullStateChanged_33;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculate
	bool ___m_ShouldRecalculate_34;
	// System.Int32 UnityEngine.UI.MaskableGraphic::m_StencilValue
	int32_t ___m_StencilValue_35;
	// UnityEngine.Vector3[] UnityEngine.UI.MaskableGraphic::m_Corners
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___m_Corners_36;
};

// UnityEngine.UI.Slider
struct Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F  : public Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712
{
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_FillRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_FillRect_20;
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_HandleRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_HandleRect_21;
	// UnityEngine.UI.Slider/Direction UnityEngine.UI.Slider::m_Direction
	int32_t ___m_Direction_22;
	// System.Single UnityEngine.UI.Slider::m_MinValue
	float ___m_MinValue_23;
	// System.Single UnityEngine.UI.Slider::m_MaxValue
	float ___m_MaxValue_24;
	// System.Boolean UnityEngine.UI.Slider::m_WholeNumbers
	bool ___m_WholeNumbers_25;
	// System.Single UnityEngine.UI.Slider::m_Value
	float ___m_Value_26;
	// UnityEngine.UI.Slider/SliderEvent UnityEngine.UI.Slider::m_OnValueChanged
	SliderEvent_t92A82EF6C62E15AF92B640FE2D960E877E8C6555* ___m_OnValueChanged_27;
	// UnityEngine.UI.Image UnityEngine.UI.Slider::m_FillImage
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ___m_FillImage_28;
	// UnityEngine.Transform UnityEngine.UI.Slider::m_FillTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_FillTransform_29;
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_FillContainerRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_FillContainerRect_30;
	// UnityEngine.Transform UnityEngine.UI.Slider::m_HandleTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_HandleTransform_31;
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_HandleContainerRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_HandleContainerRect_32;
	// UnityEngine.Vector2 UnityEngine.UI.Slider::m_Offset
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_Offset_33;
	// UnityEngine.DrivenRectTransformTracker UnityEngine.UI.Slider::m_Tracker
	DrivenRectTransformTracker_tFB0706C933E3C68E4F377C204FCEEF091F1EE0B1 ___m_Tracker_34;
	// System.Boolean UnityEngine.UI.Slider::m_DelayedUpdateVisuals
	bool ___m_DelayedUpdateVisuals_35;
};

// UnityEngine.UI.Image
struct Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// UnityEngine.Sprite UnityEngine.UI.Image::m_Sprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_Sprite_38;
	// UnityEngine.Sprite UnityEngine.UI.Image::m_OverrideSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_OverrideSprite_39;
	// UnityEngine.UI.Image/Type UnityEngine.UI.Image::m_Type
	int32_t ___m_Type_40;
	// System.Boolean UnityEngine.UI.Image::m_PreserveAspect
	bool ___m_PreserveAspect_41;
	// System.Boolean UnityEngine.UI.Image::m_FillCenter
	bool ___m_FillCenter_42;
	// UnityEngine.UI.Image/FillMethod UnityEngine.UI.Image::m_FillMethod
	int32_t ___m_FillMethod_43;
	// System.Single UnityEngine.UI.Image::m_FillAmount
	float ___m_FillAmount_44;
	// System.Boolean UnityEngine.UI.Image::m_FillClockwise
	bool ___m_FillClockwise_45;
	// System.Int32 UnityEngine.UI.Image::m_FillOrigin
	int32_t ___m_FillOrigin_46;
	// System.Single UnityEngine.UI.Image::m_AlphaHitTestMinimumThreshold
	float ___m_AlphaHitTestMinimumThreshold_47;
	// System.Boolean UnityEngine.UI.Image::m_Tracked
	bool ___m_Tracked_48;
	// System.Boolean UnityEngine.UI.Image::m_UseSpriteMesh
	bool ___m_UseSpriteMesh_49;
	// System.Single UnityEngine.UI.Image::m_PixelsPerUnitMultiplier
	float ___m_PixelsPerUnitMultiplier_50;
	// System.Single UnityEngine.UI.Image::m_CachedReferencePixelsPerUnit
	float ___m_CachedReferencePixelsPerUnit_51;
};

// TMPro.TMP_Text
struct TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// System.String TMPro.TMP_Text::m_text
	String_t* ___m_text_37;
	// System.Boolean TMPro.TMP_Text::m_IsTextBackingStringDirty
	bool ___m_IsTextBackingStringDirty_38;
	// TMPro.ITextPreprocessor TMPro.TMP_Text::m_TextPreprocessor
	RuntimeObject* ___m_TextPreprocessor_39;
	// System.Boolean TMPro.TMP_Text::m_isRightToLeft
	bool ___m_isRightToLeft_40;
	// TMPro.TMP_FontAsset TMPro.TMP_Text::m_fontAsset
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___m_fontAsset_41;
	// TMPro.TMP_FontAsset TMPro.TMP_Text::m_currentFontAsset
	TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___m_currentFontAsset_42;
	// System.Boolean TMPro.TMP_Text::m_isSDFShader
	bool ___m_isSDFShader_43;
	// UnityEngine.Material TMPro.TMP_Text::m_sharedMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_sharedMaterial_44;
	// UnityEngine.Material TMPro.TMP_Text::m_currentMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_currentMaterial_45;
	// System.Int32 TMPro.TMP_Text::m_currentMaterialIndex
	int32_t ___m_currentMaterialIndex_49;
	// UnityEngine.Material[] TMPro.TMP_Text::m_fontSharedMaterials
	MaterialU5BU5D_t2B1D11C42DB07A4400C0535F92DBB87A2E346D3D* ___m_fontSharedMaterials_50;
	// UnityEngine.Material TMPro.TMP_Text::m_fontMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_fontMaterial_51;
	// UnityEngine.Material[] TMPro.TMP_Text::m_fontMaterials
	MaterialU5BU5D_t2B1D11C42DB07A4400C0535F92DBB87A2E346D3D* ___m_fontMaterials_52;
	// System.Boolean TMPro.TMP_Text::m_isMaterialDirty
	bool ___m_isMaterialDirty_53;
	// UnityEngine.Color32 TMPro.TMP_Text::m_fontColor32
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_fontColor32_54;
	// UnityEngine.Color TMPro.TMP_Text::m_fontColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_fontColor_55;
	// UnityEngine.Color32 TMPro.TMP_Text::m_underlineColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_underlineColor_57;
	// UnityEngine.Color32 TMPro.TMP_Text::m_strikethroughColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_strikethroughColor_58;
	// System.Boolean TMPro.TMP_Text::m_enableVertexGradient
	bool ___m_enableVertexGradient_59;
	// TMPro.ColorMode TMPro.TMP_Text::m_colorMode
	int32_t ___m_colorMode_60;
	// TMPro.VertexGradient TMPro.TMP_Text::m_fontColorGradient
	VertexGradient_t2C057B53C0EA6E987C2B7BAB0305E686DA1C9A8F ___m_fontColorGradient_61;
	// TMPro.TMP_ColorGradient TMPro.TMP_Text::m_fontColorGradientPreset
	TMP_ColorGradient_t17B51752B4E9499A1FF7D875DCEC1D15A0F4AEBB* ___m_fontColorGradientPreset_62;
	// TMPro.TMP_SpriteAsset TMPro.TMP_Text::m_spriteAsset
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___m_spriteAsset_63;
	// System.Boolean TMPro.TMP_Text::m_tintAllSprites
	bool ___m_tintAllSprites_64;
	// System.Boolean TMPro.TMP_Text::m_tintSprite
	bool ___m_tintSprite_65;
	// UnityEngine.Color32 TMPro.TMP_Text::m_spriteColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_spriteColor_66;
	// TMPro.TMP_StyleSheet TMPro.TMP_Text::m_StyleSheet
	TMP_StyleSheet_t70C71699F5CB2D855C361DBB78A44C901236C859* ___m_StyleSheet_67;
	// TMPro.TMP_Style TMPro.TMP_Text::m_TextStyle
	TMP_Style_tA9E5B1B35EBFE24EF980CEA03251B638282E120C* ___m_TextStyle_68;
	// System.Int32 TMPro.TMP_Text::m_TextStyleHashCode
	int32_t ___m_TextStyleHashCode_69;
	// System.Boolean TMPro.TMP_Text::m_overrideHtmlColors
	bool ___m_overrideHtmlColors_70;
	// UnityEngine.Color32 TMPro.TMP_Text::m_faceColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_faceColor_71;
	// UnityEngine.Color32 TMPro.TMP_Text::m_outlineColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_outlineColor_72;
	// System.Single TMPro.TMP_Text::m_outlineWidth
	float ___m_outlineWidth_73;
	// System.Single TMPro.TMP_Text::m_fontSize
	float ___m_fontSize_74;
	// System.Single TMPro.TMP_Text::m_currentFontSize
	float ___m_currentFontSize_75;
	// System.Single TMPro.TMP_Text::m_fontSizeBase
	float ___m_fontSizeBase_76;
	// TMPro.TMP_TextProcessingStack`1<System.Single> TMPro.TMP_Text::m_sizeStack
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___m_sizeStack_77;
	// TMPro.FontWeight TMPro.TMP_Text::m_fontWeight
	int32_t ___m_fontWeight_78;
	// TMPro.FontWeight TMPro.TMP_Text::m_FontWeightInternal
	int32_t ___m_FontWeightInternal_79;
	// TMPro.TMP_TextProcessingStack`1<TMPro.FontWeight> TMPro.TMP_Text::m_FontWeightStack
	TMP_TextProcessingStack_1_tA5C8CED87DD9E73F6359E23B334FFB5B6F813FD4 ___m_FontWeightStack_80;
	// System.Boolean TMPro.TMP_Text::m_enableAutoSizing
	bool ___m_enableAutoSizing_81;
	// System.Single TMPro.TMP_Text::m_maxFontSize
	float ___m_maxFontSize_82;
	// System.Single TMPro.TMP_Text::m_minFontSize
	float ___m_minFontSize_83;
	// System.Int32 TMPro.TMP_Text::m_AutoSizeIterationCount
	int32_t ___m_AutoSizeIterationCount_84;
	// System.Int32 TMPro.TMP_Text::m_AutoSizeMaxIterationCount
	int32_t ___m_AutoSizeMaxIterationCount_85;
	// System.Boolean TMPro.TMP_Text::m_IsAutoSizePointSizeSet
	bool ___m_IsAutoSizePointSizeSet_86;
	// System.Single TMPro.TMP_Text::m_fontSizeMin
	float ___m_fontSizeMin_87;
	// System.Single TMPro.TMP_Text::m_fontSizeMax
	float ___m_fontSizeMax_88;
	// TMPro.FontStyles TMPro.TMP_Text::m_fontStyle
	int32_t ___m_fontStyle_89;
	// TMPro.FontStyles TMPro.TMP_Text::m_FontStyleInternal
	int32_t ___m_FontStyleInternal_90;
	// TMPro.TMP_FontStyleStack TMPro.TMP_Text::m_fontStyleStack
	TMP_FontStyleStack_t52885F172FADBC21346C835B5302167BDA8020DC ___m_fontStyleStack_91;
	// System.Boolean TMPro.TMP_Text::m_isUsingBold
	bool ___m_isUsingBold_92;
	// TMPro.HorizontalAlignmentOptions TMPro.TMP_Text::m_HorizontalAlignment
	int32_t ___m_HorizontalAlignment_93;
	// TMPro.VerticalAlignmentOptions TMPro.TMP_Text::m_VerticalAlignment
	int32_t ___m_VerticalAlignment_94;
	// TMPro.TextAlignmentOptions TMPro.TMP_Text::m_textAlignment
	int32_t ___m_textAlignment_95;
	// TMPro.HorizontalAlignmentOptions TMPro.TMP_Text::m_lineJustification
	int32_t ___m_lineJustification_96;
	// TMPro.TMP_TextProcessingStack`1<TMPro.HorizontalAlignmentOptions> TMPro.TMP_Text::m_lineJustificationStack
	TMP_TextProcessingStack_1_t243EA1B5D7FD2295D6533B953F0BBE8F52EFB8A0 ___m_lineJustificationStack_97;
	// UnityEngine.Vector3[] TMPro.TMP_Text::m_textContainerLocalCorners
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___m_textContainerLocalCorners_98;
	// System.Single TMPro.TMP_Text::m_characterSpacing
	float ___m_characterSpacing_99;
	// System.Single TMPro.TMP_Text::m_cSpacing
	float ___m_cSpacing_100;
	// System.Single TMPro.TMP_Text::m_monoSpacing
	float ___m_monoSpacing_101;
	// System.Single TMPro.TMP_Text::m_wordSpacing
	float ___m_wordSpacing_102;
	// System.Single TMPro.TMP_Text::m_lineSpacing
	float ___m_lineSpacing_103;
	// System.Single TMPro.TMP_Text::m_lineSpacingDelta
	float ___m_lineSpacingDelta_104;
	// System.Single TMPro.TMP_Text::m_lineHeight
	float ___m_lineHeight_105;
	// System.Boolean TMPro.TMP_Text::m_IsDrivenLineSpacing
	bool ___m_IsDrivenLineSpacing_106;
	// System.Single TMPro.TMP_Text::m_lineSpacingMax
	float ___m_lineSpacingMax_107;
	// System.Single TMPro.TMP_Text::m_paragraphSpacing
	float ___m_paragraphSpacing_108;
	// System.Single TMPro.TMP_Text::m_charWidthMaxAdj
	float ___m_charWidthMaxAdj_109;
	// System.Single TMPro.TMP_Text::m_charWidthAdjDelta
	float ___m_charWidthAdjDelta_110;
	// System.Boolean TMPro.TMP_Text::m_enableWordWrapping
	bool ___m_enableWordWrapping_111;
	// System.Boolean TMPro.TMP_Text::m_isCharacterWrappingEnabled
	bool ___m_isCharacterWrappingEnabled_112;
	// System.Boolean TMPro.TMP_Text::m_isNonBreakingSpace
	bool ___m_isNonBreakingSpace_113;
	// System.Boolean TMPro.TMP_Text::m_isIgnoringAlignment
	bool ___m_isIgnoringAlignment_114;
	// System.Single TMPro.TMP_Text::m_wordWrappingRatios
	float ___m_wordWrappingRatios_115;
	// TMPro.TextOverflowModes TMPro.TMP_Text::m_overflowMode
	int32_t ___m_overflowMode_116;
	// System.Int32 TMPro.TMP_Text::m_firstOverflowCharacterIndex
	int32_t ___m_firstOverflowCharacterIndex_117;
	// TMPro.TMP_Text TMPro.TMP_Text::m_linkedTextComponent
	TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9* ___m_linkedTextComponent_118;
	// TMPro.TMP_Text TMPro.TMP_Text::parentLinkedComponent
	TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9* ___parentLinkedComponent_119;
	// System.Boolean TMPro.TMP_Text::m_isTextTruncated
	bool ___m_isTextTruncated_120;
	// System.Boolean TMPro.TMP_Text::m_enableKerning
	bool ___m_enableKerning_121;
	// System.Single TMPro.TMP_Text::m_GlyphHorizontalAdvanceAdjustment
	float ___m_GlyphHorizontalAdvanceAdjustment_122;
	// System.Boolean TMPro.TMP_Text::m_enableExtraPadding
	bool ___m_enableExtraPadding_123;
	// System.Boolean TMPro.TMP_Text::checkPaddingRequired
	bool ___checkPaddingRequired_124;
	// System.Boolean TMPro.TMP_Text::m_isRichText
	bool ___m_isRichText_125;
	// System.Boolean TMPro.TMP_Text::m_parseCtrlCharacters
	bool ___m_parseCtrlCharacters_126;
	// System.Boolean TMPro.TMP_Text::m_isOverlay
	bool ___m_isOverlay_127;
	// System.Boolean TMPro.TMP_Text::m_isOrthographic
	bool ___m_isOrthographic_128;
	// System.Boolean TMPro.TMP_Text::m_isCullingEnabled
	bool ___m_isCullingEnabled_129;
	// System.Boolean TMPro.TMP_Text::m_isMaskingEnabled
	bool ___m_isMaskingEnabled_130;
	// System.Boolean TMPro.TMP_Text::isMaskUpdateRequired
	bool ___isMaskUpdateRequired_131;
	// System.Boolean TMPro.TMP_Text::m_ignoreCulling
	bool ___m_ignoreCulling_132;
	// TMPro.TextureMappingOptions TMPro.TMP_Text::m_horizontalMapping
	int32_t ___m_horizontalMapping_133;
	// TMPro.TextureMappingOptions TMPro.TMP_Text::m_verticalMapping
	int32_t ___m_verticalMapping_134;
	// System.Single TMPro.TMP_Text::m_uvLineOffset
	float ___m_uvLineOffset_135;
	// TMPro.TextRenderFlags TMPro.TMP_Text::m_renderMode
	int32_t ___m_renderMode_136;
	// TMPro.VertexSortingOrder TMPro.TMP_Text::m_geometrySortingOrder
	int32_t ___m_geometrySortingOrder_137;
	// System.Boolean TMPro.TMP_Text::m_IsTextObjectScaleStatic
	bool ___m_IsTextObjectScaleStatic_138;
	// System.Boolean TMPro.TMP_Text::m_VertexBufferAutoSizeReduction
	bool ___m_VertexBufferAutoSizeReduction_139;
	// System.Int32 TMPro.TMP_Text::m_firstVisibleCharacter
	int32_t ___m_firstVisibleCharacter_140;
	// System.Int32 TMPro.TMP_Text::m_maxVisibleCharacters
	int32_t ___m_maxVisibleCharacters_141;
	// System.Int32 TMPro.TMP_Text::m_maxVisibleWords
	int32_t ___m_maxVisibleWords_142;
	// System.Int32 TMPro.TMP_Text::m_maxVisibleLines
	int32_t ___m_maxVisibleLines_143;
	// System.Boolean TMPro.TMP_Text::m_useMaxVisibleDescender
	bool ___m_useMaxVisibleDescender_144;
	// System.Int32 TMPro.TMP_Text::m_pageToDisplay
	int32_t ___m_pageToDisplay_145;
	// System.Boolean TMPro.TMP_Text::m_isNewPage
	bool ___m_isNewPage_146;
	// UnityEngine.Vector4 TMPro.TMP_Text::m_margin
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_margin_147;
	// System.Single TMPro.TMP_Text::m_marginLeft
	float ___m_marginLeft_148;
	// System.Single TMPro.TMP_Text::m_marginRight
	float ___m_marginRight_149;
	// System.Single TMPro.TMP_Text::m_marginWidth
	float ___m_marginWidth_150;
	// System.Single TMPro.TMP_Text::m_marginHeight
	float ___m_marginHeight_151;
	// System.Single TMPro.TMP_Text::m_width
	float ___m_width_152;
	// TMPro.TMP_TextInfo TMPro.TMP_Text::m_textInfo
	TMP_TextInfo_t09A8E906329422C3F0C059876801DD695B8D524D* ___m_textInfo_153;
	// System.Boolean TMPro.TMP_Text::m_havePropertiesChanged
	bool ___m_havePropertiesChanged_154;
	// System.Boolean TMPro.TMP_Text::m_isUsingLegacyAnimationComponent
	bool ___m_isUsingLegacyAnimationComponent_155;
	// UnityEngine.Transform TMPro.TMP_Text::m_transform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_transform_156;
	// UnityEngine.RectTransform TMPro.TMP_Text::m_rectTransform
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_rectTransform_157;
	// UnityEngine.Vector2 TMPro.TMP_Text::m_PreviousRectTransformSize
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_PreviousRectTransformSize_158;
	// UnityEngine.Vector2 TMPro.TMP_Text::m_PreviousPivotPosition
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_PreviousPivotPosition_159;
	// System.Boolean TMPro.TMP_Text::<autoSizeTextContainer>k__BackingField
	bool ___U3CautoSizeTextContainerU3Ek__BackingField_160;
	// System.Boolean TMPro.TMP_Text::m_autoSizeTextContainer
	bool ___m_autoSizeTextContainer_161;
	// UnityEngine.Mesh TMPro.TMP_Text::m_mesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___m_mesh_162;
	// System.Boolean TMPro.TMP_Text::m_isVolumetricText
	bool ___m_isVolumetricText_163;
	// System.Action`1<TMPro.TMP_TextInfo> TMPro.TMP_Text::OnPreRenderText
	Action_1_tB93AB717F9D419A1BEC832FF76E74EAA32184CC1* ___OnPreRenderText_166;
	// TMPro.TMP_SpriteAnimator TMPro.TMP_Text::m_spriteAnimator
	TMP_SpriteAnimator_t2E0F016A61CA343E3222FF51E7CF0E53F9F256E4* ___m_spriteAnimator_167;
	// System.Single TMPro.TMP_Text::m_flexibleHeight
	float ___m_flexibleHeight_168;
	// System.Single TMPro.TMP_Text::m_flexibleWidth
	float ___m_flexibleWidth_169;
	// System.Single TMPro.TMP_Text::m_minWidth
	float ___m_minWidth_170;
	// System.Single TMPro.TMP_Text::m_minHeight
	float ___m_minHeight_171;
	// System.Single TMPro.TMP_Text::m_maxWidth
	float ___m_maxWidth_172;
	// System.Single TMPro.TMP_Text::m_maxHeight
	float ___m_maxHeight_173;
	// UnityEngine.UI.LayoutElement TMPro.TMP_Text::m_LayoutElement
	LayoutElement_tB1F24CC11AF4AA87015C8D8EE06D22349C5BF40A* ___m_LayoutElement_174;
	// System.Single TMPro.TMP_Text::m_preferredWidth
	float ___m_preferredWidth_175;
	// System.Single TMPro.TMP_Text::m_renderedWidth
	float ___m_renderedWidth_176;
	// System.Boolean TMPro.TMP_Text::m_isPreferredWidthDirty
	bool ___m_isPreferredWidthDirty_177;
	// System.Single TMPro.TMP_Text::m_preferredHeight
	float ___m_preferredHeight_178;
	// System.Single TMPro.TMP_Text::m_renderedHeight
	float ___m_renderedHeight_179;
	// System.Boolean TMPro.TMP_Text::m_isPreferredHeightDirty
	bool ___m_isPreferredHeightDirty_180;
	// System.Boolean TMPro.TMP_Text::m_isCalculatingPreferredValues
	bool ___m_isCalculatingPreferredValues_181;
	// System.Int32 TMPro.TMP_Text::m_layoutPriority
	int32_t ___m_layoutPriority_182;
	// System.Boolean TMPro.TMP_Text::m_isLayoutDirty
	bool ___m_isLayoutDirty_183;
	// System.Boolean TMPro.TMP_Text::m_isAwake
	bool ___m_isAwake_184;
	// System.Boolean TMPro.TMP_Text::m_isWaitingOnResourceLoad
	bool ___m_isWaitingOnResourceLoad_185;
	// TMPro.TMP_Text/TextInputSources TMPro.TMP_Text::m_inputSource
	int32_t ___m_inputSource_186;
	// System.Single TMPro.TMP_Text::m_fontScaleMultiplier
	float ___m_fontScaleMultiplier_187;
	// System.Single TMPro.TMP_Text::tag_LineIndent
	float ___tag_LineIndent_191;
	// System.Single TMPro.TMP_Text::tag_Indent
	float ___tag_Indent_192;
	// TMPro.TMP_TextProcessingStack`1<System.Single> TMPro.TMP_Text::m_indentStack
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___m_indentStack_193;
	// System.Boolean TMPro.TMP_Text::tag_NoParsing
	bool ___tag_NoParsing_194;
	// System.Boolean TMPro.TMP_Text::m_isParsingText
	bool ___m_isParsingText_195;
	// UnityEngine.Matrix4x4 TMPro.TMP_Text::m_FXMatrix
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___m_FXMatrix_196;
	// System.Boolean TMPro.TMP_Text::m_isFXMatrixSet
	bool ___m_isFXMatrixSet_197;
	// TMPro.TMP_Text/UnicodeChar[] TMPro.TMP_Text::m_TextProcessingArray
	UnicodeCharU5BU5D_t67F27D09F8EB28D2C42DFF16FE60054F157012F5* ___m_TextProcessingArray_198;
	// System.Int32 TMPro.TMP_Text::m_InternalTextProcessingArraySize
	int32_t ___m_InternalTextProcessingArraySize_199;
	// TMPro.TMP_CharacterInfo[] TMPro.TMP_Text::m_internalCharacterInfo
	TMP_CharacterInfoU5BU5D_t297D56FCF66DAA99D8FEA7C30F9F3926902C5B99* ___m_internalCharacterInfo_200;
	// System.Int32 TMPro.TMP_Text::m_totalCharacterCount
	int32_t ___m_totalCharacterCount_201;
	// System.Int32 TMPro.TMP_Text::m_characterCount
	int32_t ___m_characterCount_208;
	// System.Int32 TMPro.TMP_Text::m_firstCharacterOfLine
	int32_t ___m_firstCharacterOfLine_209;
	// System.Int32 TMPro.TMP_Text::m_firstVisibleCharacterOfLine
	int32_t ___m_firstVisibleCharacterOfLine_210;
	// System.Int32 TMPro.TMP_Text::m_lastCharacterOfLine
	int32_t ___m_lastCharacterOfLine_211;
	// System.Int32 TMPro.TMP_Text::m_lastVisibleCharacterOfLine
	int32_t ___m_lastVisibleCharacterOfLine_212;
	// System.Int32 TMPro.TMP_Text::m_lineNumber
	int32_t ___m_lineNumber_213;
	// System.Int32 TMPro.TMP_Text::m_lineVisibleCharacterCount
	int32_t ___m_lineVisibleCharacterCount_214;
	// System.Int32 TMPro.TMP_Text::m_pageNumber
	int32_t ___m_pageNumber_215;
	// System.Single TMPro.TMP_Text::m_PageAscender
	float ___m_PageAscender_216;
	// System.Single TMPro.TMP_Text::m_maxTextAscender
	float ___m_maxTextAscender_217;
	// System.Single TMPro.TMP_Text::m_maxCapHeight
	float ___m_maxCapHeight_218;
	// System.Single TMPro.TMP_Text::m_ElementAscender
	float ___m_ElementAscender_219;
	// System.Single TMPro.TMP_Text::m_ElementDescender
	float ___m_ElementDescender_220;
	// System.Single TMPro.TMP_Text::m_maxLineAscender
	float ___m_maxLineAscender_221;
	// System.Single TMPro.TMP_Text::m_maxLineDescender
	float ___m_maxLineDescender_222;
	// System.Single TMPro.TMP_Text::m_startOfLineAscender
	float ___m_startOfLineAscender_223;
	// System.Single TMPro.TMP_Text::m_startOfLineDescender
	float ___m_startOfLineDescender_224;
	// System.Single TMPro.TMP_Text::m_lineOffset
	float ___m_lineOffset_225;
	// TMPro.Extents TMPro.TMP_Text::m_meshExtents
	Extents_tA2D2F95811D0A18CB7AC3570D2D8F8CD3AF4C4A8 ___m_meshExtents_226;
	// UnityEngine.Color32 TMPro.TMP_Text::m_htmlColor
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___m_htmlColor_227;
	// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32> TMPro.TMP_Text::m_colorStack
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___m_colorStack_228;
	// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32> TMPro.TMP_Text::m_underlineColorStack
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___m_underlineColorStack_229;
	// TMPro.TMP_TextProcessingStack`1<UnityEngine.Color32> TMPro.TMP_Text::m_strikethroughColorStack
	TMP_TextProcessingStack_1_tF2CD5BE59E5EB22EA9E3EE3043A004EA918C4BB3 ___m_strikethroughColorStack_230;
	// TMPro.TMP_TextProcessingStack`1<TMPro.HighlightState> TMPro.TMP_Text::m_HighlightStateStack
	TMP_TextProcessingStack_1_t57AECDCC936A7FF1D6CF66CA11560B28A675648D ___m_HighlightStateStack_231;
	// TMPro.TMP_ColorGradient TMPro.TMP_Text::m_colorGradientPreset
	TMP_ColorGradient_t17B51752B4E9499A1FF7D875DCEC1D15A0F4AEBB* ___m_colorGradientPreset_232;
	// TMPro.TMP_TextProcessingStack`1<TMPro.TMP_ColorGradient> TMPro.TMP_Text::m_colorGradientStack
	TMP_TextProcessingStack_1_tC8FAEB17246D3B171EFD11165A5761AE39B40D0C ___m_colorGradientStack_233;
	// System.Boolean TMPro.TMP_Text::m_colorGradientPresetIsTinted
	bool ___m_colorGradientPresetIsTinted_234;
	// System.Single TMPro.TMP_Text::m_tabSpacing
	float ___m_tabSpacing_235;
	// System.Single TMPro.TMP_Text::m_spacing
	float ___m_spacing_236;
	// TMPro.TMP_TextProcessingStack`1<System.Int32>[] TMPro.TMP_Text::m_TextStyleStacks
	TMP_TextProcessingStack_1U5BU5D_t08293E0BB072311BB96170F351D1083BCA97B9B2* ___m_TextStyleStacks_237;
	// System.Int32 TMPro.TMP_Text::m_TextStyleStackDepth
	int32_t ___m_TextStyleStackDepth_238;
	// TMPro.TMP_TextProcessingStack`1<System.Int32> TMPro.TMP_Text::m_ItalicAngleStack
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___m_ItalicAngleStack_239;
	// System.Int32 TMPro.TMP_Text::m_ItalicAngle
	int32_t ___m_ItalicAngle_240;
	// TMPro.TMP_TextProcessingStack`1<System.Int32> TMPro.TMP_Text::m_actionStack
	TMP_TextProcessingStack_1_tFBA719426D68CE1F2B5849D97AF5E5D65846290C ___m_actionStack_241;
	// System.Single TMPro.TMP_Text::m_padding
	float ___m_padding_242;
	// System.Single TMPro.TMP_Text::m_baselineOffset
	float ___m_baselineOffset_243;
	// TMPro.TMP_TextProcessingStack`1<System.Single> TMPro.TMP_Text::m_baselineOffsetStack
	TMP_TextProcessingStack_1_t138EC06BE7F101AA0A3C8D2DC951E55AACE085E9 ___m_baselineOffsetStack_244;
	// System.Single TMPro.TMP_Text::m_xAdvance
	float ___m_xAdvance_245;
	// TMPro.TMP_TextElementType TMPro.TMP_Text::m_textElementType
	int32_t ___m_textElementType_246;
	// TMPro.TMP_TextElement TMPro.TMP_Text::m_cached_TextElement
	TMP_TextElement_t262A55214F712D4274485ABE5676E5254B84D0A5* ___m_cached_TextElement_247;
	// TMPro.TMP_Text/SpecialCharacter TMPro.TMP_Text::m_Ellipsis
	SpecialCharacter_t6C1DBE8C490706D1620899BAB7F0B8091AD26777 ___m_Ellipsis_248;
	// TMPro.TMP_Text/SpecialCharacter TMPro.TMP_Text::m_Underline
	SpecialCharacter_t6C1DBE8C490706D1620899BAB7F0B8091AD26777 ___m_Underline_249;
	// TMPro.TMP_SpriteAsset TMPro.TMP_Text::m_defaultSpriteAsset
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___m_defaultSpriteAsset_250;
	// TMPro.TMP_SpriteAsset TMPro.TMP_Text::m_currentSpriteAsset
	TMP_SpriteAsset_t81F779E6F705CE190DC0D1F93A954CB8B1774B39* ___m_currentSpriteAsset_251;
	// System.Int32 TMPro.TMP_Text::m_spriteCount
	int32_t ___m_spriteCount_252;
	// System.Int32 TMPro.TMP_Text::m_spriteIndex
	int32_t ___m_spriteIndex_253;
	// System.Int32 TMPro.TMP_Text::m_spriteAnimationID
	int32_t ___m_spriteAnimationID_254;
	// System.Boolean TMPro.TMP_Text::m_ignoreActiveState
	bool ___m_ignoreActiveState_257;
	// TMPro.TMP_Text/TextBackingContainer TMPro.TMP_Text::m_TextBackingArray
	TextBackingContainer_t33D1CE628E7B26C45EDAC1D87BEF2DD22A5C6361 ___m_TextBackingArray_258;
	// System.Decimal[] TMPro.TMP_Text::k_Power
	DecimalU5BU5D_t93BA0C88FA80728F73B792EE1A5199D0C060B615* ___k_Power_259;
};

// TMPro.TextMeshProUGUI
struct TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957  : public TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9
{
	// System.Boolean TMPro.TextMeshProUGUI::m_isRebuildingLayout
	bool ___m_isRebuildingLayout_266;
	// UnityEngine.Coroutine TMPro.TextMeshProUGUI::m_DelayedGraphicRebuild
	Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* ___m_DelayedGraphicRebuild_267;
	// UnityEngine.Coroutine TMPro.TextMeshProUGUI::m_DelayedMaterialRebuild
	Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* ___m_DelayedMaterialRebuild_268;
	// UnityEngine.Rect TMPro.TextMeshProUGUI::m_ClipRect
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___m_ClipRect_269;
	// System.Boolean TMPro.TextMeshProUGUI::m_ValidRect
	bool ___m_ValidRect_270;
	// System.Action`1<TMPro.TMP_TextInfo> TMPro.TextMeshProUGUI::OnPreRenderText
	Action_1_tB93AB717F9D419A1BEC832FF76E74EAA32184CC1* ___OnPreRenderText_271;
	// System.Boolean TMPro.TextMeshProUGUI::m_hasFontAssetChanged
	bool ___m_hasFontAssetChanged_272;
	// TMPro.TMP_SubMeshUI[] TMPro.TextMeshProUGUI::m_subTextObjects
	TMP_SubMeshUIU5BU5D_tC77B263183A59A75345C26152457207EAC3BBF29* ___m_subTextObjects_273;
	// System.Single TMPro.TextMeshProUGUI::m_previousLossyScaleY
	float ___m_previousLossyScaleY_274;
	// UnityEngine.Vector3[] TMPro.TextMeshProUGUI::m_RectTransformCorners
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___m_RectTransformCorners_275;
	// UnityEngine.CanvasRenderer TMPro.TextMeshProUGUI::m_canvasRenderer
	CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860* ___m_canvasRenderer_276;
	// UnityEngine.Canvas TMPro.TextMeshProUGUI::m_canvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ___m_canvas_277;
	// System.Single TMPro.TextMeshProUGUI::m_CanvasScaleFactor
	float ___m_CanvasScaleFactor_278;
	// System.Boolean TMPro.TextMeshProUGUI::m_isFirstAllocation
	bool ___m_isFirstAllocation_279;
	// System.Int32 TMPro.TextMeshProUGUI::m_max_characters
	int32_t ___m_max_characters_280;
	// UnityEngine.Material TMPro.TextMeshProUGUI::m_baseMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_baseMaterial_281;
	// System.Boolean TMPro.TextMeshProUGUI::m_isScrollRegionSet
	bool ___m_isScrollRegionSet_282;
	// UnityEngine.Vector4 TMPro.TextMeshProUGUI::m_maskOffset
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_maskOffset_283;
	// UnityEngine.Matrix4x4 TMPro.TextMeshProUGUI::m_EnvMapMatrix
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___m_EnvMapMatrix_284;
	// System.Boolean TMPro.TextMeshProUGUI::m_isRegisteredForEvents
	bool ___m_isRegisteredForEvents_285;
};

// <Module>

// <Module>

// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	GameObjectU5BU5D_tFF67550DFCE87096D7A3734EA15B75896B2722CF* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<UnityEngine.GameObject>

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Object>

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// UIManager/<BankStars>d__64

// UIManager/<BankStars>d__64

// UIManager/<EndCreditsRoll>d__72

// UIManager/<EndCreditsRoll>d__72

// UIManager/<FinishSentence>d__58

// UIManager/<FinishSentence>d__58

// UIManager/<HintDialogue>d__73

// UIManager/<HintDialogue>d__73

// UIManager/<MainMenuReset>d__71

// UIManager/<MainMenuReset>d__71

// UIManager/<TypeSentence>d__57

// UIManager/<TypeSentence>d__57

// System.Collections.Generic.List`1/Enumerator<UnityEngine.GameObject>

// System.Collections.Generic.List`1/Enumerator<UnityEngine.GameObject>

// System.Collections.Generic.List`1/Enumerator<System.Object>

// System.Collections.Generic.List`1/Enumerator<System.Object>

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	// System.Byte[] System.Char::s_categoryForLatin1
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1_3;
};

// System.Char

// UnityEngine.Color

// UnityEngine.Color

// System.Int32

// System.Int32

// System.IntPtr
struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.IntPtr

// System.Single

// System.Single

// System.Void

// System.Void

// UnityEngine.WaitForSeconds

// UnityEngine.WaitForSeconds

// UnityEngine.WaitForSecondsRealtime

// UnityEngine.WaitForSecondsRealtime

// UnityEngine.Coroutine

// UnityEngine.Coroutine

// System.Delegate

// System.Delegate

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// UnityEngine.Component

// UnityEngine.Component

// UnityEngine.GameObject

// UnityEngine.GameObject

// System.Action`1<System.Boolean>

// System.Action`1<System.Boolean>

// System.Action`1<UnityEngine.GameObject>

// System.Action`1<UnityEngine.GameObject>

// System.Action`1<GameState>

// System.Action`1<GameState>

// System.Action`1<System.Int32>

// System.Action`1<System.Int32>

// System.Action`1<System.String>

// System.Action`1<System.String>

// System.Action

// System.Action

// UnityEngine.AnimationClip

// UnityEngine.AnimationClip

// UnityEngine.Behaviour

// UnityEngine.Behaviour

// System.NotSupportedException

// System.NotSupportedException

// StageDialogue

// StageDialogue

// UnityEngine.Transform

// UnityEngine.Transform

// UnityEngine.Animation

// UnityEngine.Animation

// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_StaticFields
{
	// UnityEngine.Canvas/WillRenderCanvases UnityEngine.Canvas::preWillRenderCanvases
	WillRenderCanvases_tA4A6E66DBA797DCB45B995DBA449A9D1D80D0FBC* ___preWillRenderCanvases_4;
	// UnityEngine.Canvas/WillRenderCanvases UnityEngine.Canvas::willRenderCanvases
	WillRenderCanvases_tA4A6E66DBA797DCB45B995DBA449A9D1D80D0FBC* ___willRenderCanvases_5;
	// System.Action`1<System.Int32> UnityEngine.Canvas::<externBeginRenderOverlays>k__BackingField
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___U3CexternBeginRenderOverlaysU3Ek__BackingField_6;
	// System.Action`2<System.Int32,System.Int32> UnityEngine.Canvas::<externRenderOverlaysBefore>k__BackingField
	Action_2_tD7438462601D3939500ED67463331FE00CFFBDB8* ___U3CexternRenderOverlaysBeforeU3Ek__BackingField_7;
	// System.Action`1<System.Int32> UnityEngine.Canvas::<externEndRenderOverlays>k__BackingField
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___U3CexternEndRenderOverlaysU3Ek__BackingField_8;
};

// UnityEngine.Canvas

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// TMPro.TMP_FontAsset
struct TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160_StaticFields
{
	// Unity.Profiling.ProfilerMarker TMPro.TMP_FontAsset::k_ReadFontAssetDefinitionMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_ReadFontAssetDefinitionMarker_45;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_FontAsset::k_AddSynthesizedCharactersMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_AddSynthesizedCharactersMarker_46;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_FontAsset::k_TryAddCharacterMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_TryAddCharacterMarker_47;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_FontAsset::k_TryAddCharactersMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_TryAddCharactersMarker_48;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_FontAsset::k_UpdateGlyphAdjustmentRecordsMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_UpdateGlyphAdjustmentRecordsMarker_49;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_FontAsset::k_ClearFontAssetDataMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_ClearFontAssetDataMarker_50;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_FontAsset::k_UpdateFontAssetDataMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_UpdateFontAssetDataMarker_51;
	// System.String TMPro.TMP_FontAsset::s_DefaultMaterialSuffix
	String_t* ___s_DefaultMaterialSuffix_52;
	// System.Collections.Generic.HashSet`1<System.Int32> TMPro.TMP_FontAsset::k_SearchedFontAssetLookup
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___k_SearchedFontAssetLookup_54;
	// System.Collections.Generic.List`1<TMPro.TMP_FontAsset> TMPro.TMP_FontAsset::k_FontAssets_FontFeaturesUpdateQueue
	List_1_t06C3ABB0C6F2347B32881E33D154431EADAE3ECF* ___k_FontAssets_FontFeaturesUpdateQueue_55;
	// System.Collections.Generic.HashSet`1<System.Int32> TMPro.TMP_FontAsset::k_FontAssets_FontFeaturesUpdateQueueLookup
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___k_FontAssets_FontFeaturesUpdateQueueLookup_56;
	// System.Collections.Generic.List`1<TMPro.TMP_FontAsset> TMPro.TMP_FontAsset::k_FontAssets_AtlasTexturesUpdateQueue
	List_1_t06C3ABB0C6F2347B32881E33D154431EADAE3ECF* ___k_FontAssets_AtlasTexturesUpdateQueue_57;
	// System.Collections.Generic.HashSet`1<System.Int32> TMPro.TMP_FontAsset::k_FontAssets_AtlasTexturesUpdateQueueLookup
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___k_FontAssets_AtlasTexturesUpdateQueueLookup_58;
	// System.UInt32[] TMPro.TMP_FontAsset::k_GlyphIndexArray
	UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___k_GlyphIndexArray_69;
};

// TMPro.TMP_FontAsset

// AudioManager
struct AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_StaticFields
{
	// AudioManager AudioManager::Instance
	AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613* ___Instance_26;
};

// AudioManager

// UnityEngine.AudioSource

// UnityEngine.AudioSource

// ButtonToggle

// ButtonToggle

// DialogueManager
struct DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_StaticFields
{
	// DialogueManager DialogueManager::Instance
	DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* ___Instance_8;
	// System.Action`1<System.String> DialogueManager::OnNextSentence
	Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A* ___OnNextSentence_9;
	// System.Action`1<System.String> DialogueManager::OnNextAnswer
	Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A* ___OnNextAnswer_10;
	// System.Action DialogueManager::OnDialogueEnd
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnDialogueEnd_11;
	// System.Action`1<System.Boolean> DialogueManager::OnDialogueOpen
	Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* ___OnDialogueOpen_12;
};

// DialogueManager

// GameManager
struct GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields
{
	// StageDialogue GameManager::_currentStageDialogue
	StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* ____currentStageDialogue_13;
	// System.Single GameManager::_maxSpeed
	float ____maxSpeed_29;
	// System.Single GameManager::_tileLength
	float ____tileLength_30;
	// System.Single GameManager::_speedMultiplier
	float ____speedMultiplier_31;
	// System.Single GameManager::_tileAlpha
	float ____tileAlpha_32;
	// System.Int32 GameManager::_stageProgress
	int32_t ____stageProgress_33;
	// System.Int32 GameManager::_stageLength
	int32_t ____stageLength_34;
	// System.Int32 GameManager::_transitionProgress
	int32_t ____transitionProgress_35;
	// System.Int32 GameManager::_acquiredStars
	int32_t ____acquiredStars_36;
	// System.Int32 GameManager::_requiredStars
	int32_t ____requiredStars_37;
	// System.Int32 GameManager::_currentScore
	int32_t ____currentScore_38;
	// System.Int32 GameManager::_loseCounter
	int32_t ____loseCounter_39;
	// System.Int32 GameManager::_bonusStarLevel
	int32_t ____bonusStarLevel_40;
	// System.Int32 GameManager::_chargedTileCounter
	int32_t ____chargedTileCounter_41;
	// System.Single GameManager::_tileColorHue
	float ____tileColorHue_42;
	// System.Boolean GameManager::_firstStarGained
	bool ____firstStarGained_43;
	// System.Boolean GameManager::_secondStarGained
	bool ____secondStarGained_44;
	// System.Boolean GameManager::_thirdStarGained
	bool ____thirdStarGained_45;
	// System.Boolean GameManager::_isAudioEnabled
	bool ____isAudioEnabled_46;
	// System.Boolean GameManager::_isMusicEnabled
	bool ____isMusicEnabled_47;
	// System.Boolean GameManager::_isHapticEnabled
	bool ____isHapticEnabled_48;
	// System.Boolean GameManager::_isTutorialsEnabled
	bool ____isTutorialsEnabled_49;
	// System.Boolean GameManager::_isStageMenuOpen
	bool ____isStageMenuOpen_50;
	// System.Boolean GameManager::_isInMainMenu
	bool ____isInMainMenu_51;
	// System.Boolean GameManager::_needDialogueBoxHint
	bool ____needDialogueBoxHint_52;
	// System.Boolean GameManager::_spawnPurpleCrystal
	bool ____spawnPurpleCrystal_53;
	// System.Boolean GameManager::_spawnGoldCrystal
	bool ____spawnGoldCrystal_54;
	// System.Boolean GameManager::_spawnGreenCrystal
	bool ____spawnGreenCrystal_55;
	// System.Boolean GameManager::_isGameOver
	bool ____isGameOver_56;
	// System.Boolean GameManager::_repeatingStage
	bool ____repeatingStage_57;
	// System.Boolean GameManager::_compassionateVictoryAchieved
	bool ____compassionateVictoryAchieved_58;
	// UnityEngine.Vector3 GameManager::_tileSpeed
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ____tileSpeed_59;
	// UnityEngine.Vector3 GameManager::_transitionSpeed
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ____transitionSpeed_60;
	// UnityEngine.Vector3 GameManager::_boardLength
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ____boardLength_61;
	// Answer GameManager::_stageAnswerQuality
	int32_t ____stageAnswerQuality_62;
	// System.Action`1<GameState> GameManager::OnStateChanged
	Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978* ___OnStateChanged_63;
	// System.Action GameManager::OnSetupNextStage
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnSetupNextStage_64;
	// System.Action`1<System.Int32> GameManager::OnStarBonusChanged
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___OnStarBonusChanged_65;
	// System.Action`1<System.Int32> GameManager::OnCompassionateStarAdded
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___OnCompassionateStarAdded_66;
	// System.Action GameManager::OnCompassionateStarsReset
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnCompassionateStarsReset_67;
	// System.Action GameManager::OnCompassionateVictory
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnCompassionateVictory_68;
	// System.Action GameManager::OnStageEnd
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnStageEnd_69;
	// System.Action`1<UnityEngine.GameObject> GameManager::OnRunnerSpawned
	Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C* ___OnRunnerSpawned_70;
	// System.Action`1<System.Int32> GameManager::OnStarGained
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___OnStarGained_71;
	// System.Action GameManager::OnMainMenuOpen
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnMainMenuOpen_72;
	// System.Action GameManager::OnMainMenuClose
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnMainMenuClose_73;
	// System.Action GameManager::OnGameOver
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnGameOver_74;
	// System.Action GameManager::OnQuitToMenu
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnQuitToMenu_75;
	// System.Action`1<System.Int32> GameManager::OnCompassionateChargeUp
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___OnCompassionateChargeUp_76;
	// System.Action`1<System.Boolean> GameManager::OnCompassionateStarsToggle
	Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* ___OnCompassionateStarsToggle_77;
	// System.Action`1<System.Int32> GameManager::OnNextTutorial
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___OnNextTutorial_78;
	// System.Action GameManager::OnShowEmptySlots
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnShowEmptySlots_79;
	// System.Action GameManager::OnDisableTutorials
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___OnDisableTutorials_80;
	// GameState GameManager::CurrentState
	int32_t ___CurrentState_81;
	// GameManager GameManager::Instance
	GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* ___Instance_82;
	// UnityEngine.GameObject GameManager::LastCrystal
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___LastCrystal_83;
	// System.Single GameManager::HighestDrawnRowHeight
	float ___HighestDrawnRowHeight_84;
	// System.Single GameManager::RunnerHeight
	float ___RunnerHeight_85;
	// System.Int32 GameManager::NumberOfRows
	int32_t ___NumberOfRows_86;
	// System.Boolean GameManager::IsRunnerInTransition
	bool ___IsRunnerInTransition_87;
	// System.Boolean GameManager::IsStageCompleted
	bool ___IsStageCompleted_88;
	// System.Boolean[] GameManager::DoTutorial
	BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* ___DoTutorial_89;
	// System.Boolean GameManager::GreenCrystalTouched
	bool ___GreenCrystalTouched_90;
	// System.Boolean GameManager::GameUnderway
	bool ___GameUnderway_91;
	// System.Int32 GameManager::GlobalDialogueCounter
	int32_t ___GlobalDialogueCounter_92;
	// System.Int32 GameManager::HighScore
	int32_t ___HighScore_93;
	// System.Int32 GameManager::PreviousHighScore
	int32_t ___PreviousHighScore_94;
};

// GameManager

// UIManager

// UIManager

// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Graphic::s_DefaultUI
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_DefaultUI_4;
	// UnityEngine.Texture2D UnityEngine.UI.Graphic::s_WhiteTexture
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___s_WhiteTexture_5;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::s_Mesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___s_Mesh_21;
	// UnityEngine.UI.VertexHelper UnityEngine.UI.Graphic::s_VertexHelper
	VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE* ___s_VertexHelper_22;
};

// UnityEngine.UI.Graphic

// UnityEngine.UI.Button

// UnityEngine.UI.Button

// UnityEngine.UI.Slider

// UnityEngine.UI.Slider

// UnityEngine.UI.Image
struct Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Image::s_ETC1DefaultUI
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_ETC1DefaultUI_37;
	// UnityEngine.Vector2[] UnityEngine.UI.Image::s_VertScratch
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___s_VertScratch_52;
	// UnityEngine.Vector2[] UnityEngine.UI.Image::s_UVScratch
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___s_UVScratch_53;
	// UnityEngine.Vector3[] UnityEngine.UI.Image::s_Xy
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___s_Xy_54;
	// UnityEngine.Vector3[] UnityEngine.UI.Image::s_Uv
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___s_Uv_55;
	// System.Collections.Generic.List`1<UnityEngine.UI.Image> UnityEngine.UI.Image::m_TrackedTexturelessImages
	List_1_tE6BB71ABF15905EFA2BE92C38A2716547AEADB19* ___m_TrackedTexturelessImages_56;
	// System.Boolean UnityEngine.UI.Image::s_Initialized
	bool ___s_Initialized_57;
};

// UnityEngine.UI.Image

// TMPro.TMP_Text
struct TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9_StaticFields
{
	// TMPro.MaterialReference[] TMPro.TMP_Text::m_materialReferences
	MaterialReferenceU5BU5D_t7491D335AB3E3E13CE9C0F5E931F396F6A02E1F2* ___m_materialReferences_46;
	// System.Collections.Generic.Dictionary`2<System.Int32,System.Int32> TMPro.TMP_Text::m_materialReferenceIndexLookup
	Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180* ___m_materialReferenceIndexLookup_47;
	// TMPro.TMP_TextProcessingStack`1<TMPro.MaterialReference> TMPro.TMP_Text::m_materialReferenceStack
	TMP_TextProcessingStack_1_tB03E08F69415B281A5A81138F09E49EE58402DF9 ___m_materialReferenceStack_48;
	// UnityEngine.Color32 TMPro.TMP_Text::s_colorWhite
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___s_colorWhite_56;
	// System.Func`3<System.Int32,System.String,TMPro.TMP_FontAsset> TMPro.TMP_Text::OnFontAssetRequest
	Func_3_tC721DF8CDD07ED66A4833A19A2ED2302608C906C* ___OnFontAssetRequest_164;
	// System.Func`3<System.Int32,System.String,TMPro.TMP_SpriteAsset> TMPro.TMP_Text::OnSpriteAssetRequest
	Func_3_t6F6D9932638EA1A5A45303C6626C818C25D164E5* ___OnSpriteAssetRequest_165;
	// System.Char[] TMPro.TMP_Text::m_htmlTag
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_htmlTag_188;
	// TMPro.RichTextTagAttribute[] TMPro.TMP_Text::m_xmlAttribute
	RichTextTagAttributeU5BU5D_t5816316EFD8F59DBC30B9F88E15828C564E47B6D* ___m_xmlAttribute_189;
	// System.Single[] TMPro.TMP_Text::m_attributeParameterValues
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___m_attributeParameterValues_190;
	// TMPro.WordWrapState TMPro.TMP_Text::m_SavedWordWrapState
	WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A ___m_SavedWordWrapState_202;
	// TMPro.WordWrapState TMPro.TMP_Text::m_SavedLineState
	WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A ___m_SavedLineState_203;
	// TMPro.WordWrapState TMPro.TMP_Text::m_SavedEllipsisState
	WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A ___m_SavedEllipsisState_204;
	// TMPro.WordWrapState TMPro.TMP_Text::m_SavedLastValidState
	WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A ___m_SavedLastValidState_205;
	// TMPro.WordWrapState TMPro.TMP_Text::m_SavedSoftLineBreakState
	WordWrapState_t80F67D8CAA9B1A0A3D5266521E23A9F3100EDD0A ___m_SavedSoftLineBreakState_206;
	// TMPro.TMP_TextProcessingStack`1<TMPro.WordWrapState> TMPro.TMP_Text::m_EllipsisInsertionCandidateStack
	TMP_TextProcessingStack_1_t2DDA00FFC64AF6E3AFD475AB2086D16C34787E0F ___m_EllipsisInsertionCandidateStack_207;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_Text::k_ParseTextMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_ParseTextMarker_255;
	// Unity.Profiling.ProfilerMarker TMPro.TMP_Text::k_InsertNewLineMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_InsertNewLineMarker_256;
	// UnityEngine.Vector2 TMPro.TMP_Text::k_LargePositiveVector2
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___k_LargePositiveVector2_260;
	// UnityEngine.Vector2 TMPro.TMP_Text::k_LargeNegativeVector2
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___k_LargeNegativeVector2_261;
	// System.Single TMPro.TMP_Text::k_LargePositiveFloat
	float ___k_LargePositiveFloat_262;
	// System.Single TMPro.TMP_Text::k_LargeNegativeFloat
	float ___k_LargeNegativeFloat_263;
	// System.Int32 TMPro.TMP_Text::k_LargePositiveInt
	int32_t ___k_LargePositiveInt_264;
	// System.Int32 TMPro.TMP_Text::k_LargeNegativeInt
	int32_t ___k_LargeNegativeInt_265;
};

// TMPro.TMP_Text

// TMPro.TextMeshProUGUI
struct TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957_StaticFields
{
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_GenerateTextMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_GenerateTextMarker_286;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_SetArraySizesMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_SetArraySizesMarker_287;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_GenerateTextPhaseIMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_GenerateTextPhaseIMarker_288;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_ParseMarkupTextMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_ParseMarkupTextMarker_289;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_CharacterLookupMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_CharacterLookupMarker_290;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_HandleGPOSFeaturesMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_HandleGPOSFeaturesMarker_291;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_CalculateVerticesPositionMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_CalculateVerticesPositionMarker_292;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_ComputeTextMetricsMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_ComputeTextMetricsMarker_293;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_HandleVisibleCharacterMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_HandleVisibleCharacterMarker_294;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_HandleWhiteSpacesMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_HandleWhiteSpacesMarker_295;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_HandleHorizontalLineBreakingMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_HandleHorizontalLineBreakingMarker_296;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_HandleVerticalLineBreakingMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_HandleVerticalLineBreakingMarker_297;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_SaveGlyphVertexDataMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_SaveGlyphVertexDataMarker_298;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_ComputeCharacterAdvanceMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_ComputeCharacterAdvanceMarker_299;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_HandleCarriageReturnMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_HandleCarriageReturnMarker_300;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_HandleLineTerminationMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_HandleLineTerminationMarker_301;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_SavePageInfoMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_SavePageInfoMarker_302;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_SaveProcessingStatesMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_SaveProcessingStatesMarker_303;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_GenerateTextPhaseIIMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_GenerateTextPhaseIIMarker_304;
	// Unity.Profiling.ProfilerMarker TMPro.TextMeshProUGUI::k_GenerateTextPhaseIIIMarker
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___k_GenerateTextPhaseIIIMarker_305;
};

// TMPro.TextMeshProUGUI
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// UnityEngine.UI.Slider[]
struct SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55  : public RuntimeArray
{
	ALIGN_FIELD (8) Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* m_Items[1];

	inline Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppChar m_Items[1];

	inline Il2CppChar GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppChar value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Il2CppChar GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppChar value)
	{
		m_Items[index] = value;
	}
};
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// System.Void System.Action`1<System.Int32>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87_gshared (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Boolean>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501_gshared (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Object>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Int32Enum>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_m8EDF953DA7FF0E33AE19FB51BD7DBDB7C495CFE0_gshared (Action_1_tC926860F20D428DA3E93D6FBA36420E904DD903B* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponentInParent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponentInParent_TisRuntimeObject_m6746D6BB99912B1B509746C993906492F86CD119_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponentInChildren<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponentInChildren_TisRuntimeObject_mE483A27E876DE8E4E6901D6814837F81D7C42F65_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.List`1/Enumerator<T> System.Collections.Generic.List`1<System.Object>::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1/Enumerator<System.Object>::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1/Enumerator<System.Object>::get_Current()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1/Enumerator<System.Object>::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Clear()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// T UnityEngine.Object::Instantiate<System.Object>(T,UnityEngine.Transform)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Object_Instantiate_TisRuntimeObject_m75BF3B0A3747B60491845FA41612FE7F795F0A59_gshared (RuntimeObject* ___0_original, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___1_parent, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Int32>::Invoke(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mAC3C34BA1905AB5B79E483CD9BB082B7D667F703_gshared_inline (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* __this, int32_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;

// System.Boolean GameManager::get_IsAudioEnabled()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsAudioEnabled_m89BB8BC284997DB0FC96A9405C1B035E984C72E1_inline (const RuntimeMethod* method) ;
// System.Boolean GameManager::get_IsMusicEnabled()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsMusicEnabled_mD149DDFF2ABF807F087BB4D6DA0625F0C8D55065_inline (const RuntimeMethod* method) ;
// System.Boolean GameManager::get_IsHapticEnabled()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsHapticEnabled_m64A912E276482E96D33E589E15B102FA68140AC5_inline (const RuntimeMethod* method) ;
// System.Boolean GameManager::get_IsTutorialsEnabled()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsTutorialsEnabled_m2DCFC9B855219403A47C511B56C3E33EF7C35314_inline (const RuntimeMethod* method) ;
// System.Void ButtonToggle::UpdateImage()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) ;
// System.Void System.Action::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Combine(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00 (Delegate_t* ___0_a, Delegate_t* ___1_b, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Remove(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3 (Delegate_t* ___0_source, Delegate_t* ___1_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Behaviour::set_enabled(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A (Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void ButtonToggle::Toggle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_Toggle_mC2AF8D3392D320EA1C3617A41BDEFB7324B9EC05 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) ;
// System.Void AudioManager::MuteAudio(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioManager_MuteAudio_m57EDEBFF009C988B17D3B3A6BBCF0358DD5868AB (AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613* __this, bool ___0_enabled, const RuntimeMethod* method) ;
// System.Void GameManager::set_IsAudioEnabled(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsAudioEnabled_mF8233819F6804D705F704141A489FC0E56D97D62_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void AudioManager::MuteMusic(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioManager_MuteMusic_m9173DCB0C32C8E9D16D1618B08A1E25614B11C4B (AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613* __this, bool ___0_enabled, const RuntimeMethod* method) ;
// System.Void GameManager::set_IsMusicEnabled(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsMusicEnabled_m32A5D2E12A9CD4D37B4DE1C06A1B79F53759575D_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::set_IsHapticEnabled(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsHapticEnabled_m32528E40700F774A8501FA6E2FDF22FE25F907D7_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::set_IsTutorialsEnabled(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsTutorialsEnabled_m5F855CEEE242B7D1F3181362EAC2C6CF50E589E1_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::SetActive(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.String System.Int32::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Int32>::.ctor(System.Object,System.IntPtr)
inline void Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87 (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void GameManager::add_OnStarBonusChanged(System.Action`1<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnStarBonusChanged_m3E2F922C8D11C1400DF7524BA2E3D62C76F1E6C5 (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::add_OnCompassionateChargeUp(System.Action`1<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnCompassionateChargeUp_m2052CD2BBF7224CC67CB8C3B6904783244628C77 (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___0_value, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Boolean>::.ctor(System.Object,System.IntPtr)
inline void Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501 (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void GameManager::add_OnCompassionateStarsReset(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnCompassionateStarsReset_m0829D0535935B26679FAD278D2A738279455403C (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void System.Action`1<UnityEngine.GameObject>::.ctor(System.Object,System.IntPtr)
inline void Action_1__ctor_m3FA37AFA5AAB09F49F9C00A7D5B2A5F3D83CBB01 (Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void GameManager::add_OnRunnerSpawned(System.Action`1<UnityEngine.GameObject>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnRunnerSpawned_mABA868571A5C4B0AEA6E4C9CD6FA6F3A9F8F30B1 (Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::add_OnStageEnd(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnStageEnd_m6762C7BA8C01352592448CC95F7A5DD8E40986B3 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void System.Action`1<GameState>::.ctor(System.Object,System.IntPtr)
inline void Action_1__ctor_mBCE4C560DFFB6626B4C265665FDFE6B1A1F1E7D4 (Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_m8EDF953DA7FF0E33AE19FB51BD7DBDB7C495CFE0_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void GameManager::add_OnStateChanged(System.Action`1<GameState>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnStateChanged_m1B142A23151688D2673259C2F39443C0E111D96D (Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::add_OnMainMenuOpen(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnMainMenuOpen_m4ED8B1035649550741C350E2BD25C72904D83484 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::add_OnStarGained(System.Action`1<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnStarGained_mB8875BB8EF7DA5D0A547AA70F0713A020A4BBAFE (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::add_OnGameOver(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_add_OnGameOver_m3F4A6D0778A05C2401E44CA3CCBCB1F0B158F105 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.String>::.ctor(System.Object,System.IntPtr)
inline void Action_1__ctor_m9DC2953C55C4D7D4B7BEFE03D84DA1F9362D652C (Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void DialogueManager::add_OnNextSentence(System.Action`1<System.String>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DialogueManager_add_OnNextSentence_m68AA8DA5C147EC06070D33642D194332649466D3 (Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A* ___0_value, const RuntimeMethod* method) ;
// System.Void DialogueManager::add_OnDialogueEnd(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DialogueManager_add_OnDialogueEnd_mB5C9653BE9E133506EDF81FC05DAE4750D441E71 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void Row::add_OnFirstRowsReady(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Row_add_OnFirstRowsReady_m791BA7EA4FBECF36F12C73E1644980C58C437E29 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnStarBonusChanged(System.Action`1<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnStarBonusChanged_m9DD0694B3CCED09AB33E710C39A95657694EC49B (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnCompassionateChargeUp(System.Action`1<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnCompassionateChargeUp_m038899309B12D97F39DCA9E68F34BB8A5A74590A (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnCompassionateStarsReset(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnCompassionateStarsReset_m7FA693CF2CB8916CC9AE4758576D6A8788033C10 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnRunnerSpawned(System.Action`1<UnityEngine.GameObject>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnRunnerSpawned_mB4E63D8A77EA90664FBB93E96712CE33796E7EBC (Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnStageEnd(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnStageEnd_m6F1681650AB40E8412FAD7320276742D0BAE4159 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnStateChanged(System.Action`1<GameState>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnStateChanged_mBE73BDEFC471BB001E101A182EAB87BF62699DEF (Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnMainMenuOpen(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnMainMenuOpen_mBAFB451D7582B215B4D888145CE925F6B784FB3D (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnStarGained(System.Action`1<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnStarGained_mDD44B3EBF6FFE7EB1823BA7D67735DCDE1D0D27D (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___0_value, const RuntimeMethod* method) ;
// System.Void GameManager::remove_OnGameOver(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_remove_OnGameOver_mE474DA270549E34052B3B285CC6BD07F94BB3743 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void DialogueManager::remove_OnNextSentence(System.Action`1<System.String>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DialogueManager_remove_OnNextSentence_mDE42E6FEFC3ED09395FA3227264EEEDC32A0A8E4 (Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A* ___0_value, const RuntimeMethod* method) ;
// System.Void DialogueManager::remove_OnDialogueEnd(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DialogueManager_remove_OnDialogueEnd_m42E419EFBB96C5BADCBE4488F9A11CDC8BB462D2 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Void Row::remove_OnFirstRowsReady(System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Row_remove_OnFirstRowsReady_mEF39E4D2A1EBB5E603FF0AB437DFF277AF665905 (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_value, const RuntimeMethod* method) ;
// System.Int32 GameManager::get_RequiredStars()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline (const RuntimeMethod* method) ;
// System.Int32 GameManager::get_CompassionateStars()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_CompassionateStars_mC10D44463CFC587C028B958A747A6A7BF8AFB799_inline (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) ;
// System.Boolean DialogueManager::get_IsQuery()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool DialogueManager_get_IsQuery_mCB820DB1AE6081487F94B1108B87FBACF7816DD8_inline (DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* __this, const RuntimeMethod* method) ;
// System.Void TMPro.TMP_Text::set_font(TMPro.TMP_FontAsset)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TMP_Text_set_font_mC55E4A8C1C09595031384B35F2C2FB2FC3479E83 (TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9* __this, TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* ___0_value, const RuntimeMethod* method) ;
// UnityEngine.Transform TMPro.TMP_Text::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* TMP_Text_get_transform_m6BD41E08BFCFCE722DFCE4627626AD60CA99CCA8 (TMP_Text_tE8D677872D43AD4B2AAF0D6101692A17D0B251A9* __this, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponentInParent<UnityEngine.UI.Image>()
inline Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* Component_GetComponentInParent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m0EE7FD91A12A618B79D1B60D2ED73142D7CD65E9 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponentInParent_TisRuntimeObject_m6746D6BB99912B1B509746C993906492F86CD119_gshared)(__this, method);
}
// T UnityEngine.Component::GetComponentInParent<UnityEngine.Canvas>()
inline Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponentInParent_TisRuntimeObject_m6746D6BB99912B1B509746C993906492F86CD119_gshared)(__this, method);
}
// System.Collections.IEnumerator UIManager::TypeSentence(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_TypeSentence_m6FAECFDF6029B0FA540597A1F1067990CE71A924 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, String_t* ___0_sentence, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::StopCoroutine(System.Collections.IEnumerator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour_StopCoroutine_mF9E93B82091E804595BE13AA29F9AB7517F7E04A (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, RuntimeObject* ___0_routine, const RuntimeMethod* method) ;
// System.Collections.IEnumerator UIManager::FinishSentence()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_FinishSentence_mFBECD5FA7AD2A42506461EFB4AA0734856796177 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// UnityEngine.Coroutine UnityEngine.MonoBehaviour::StartCoroutine(System.Collections.IEnumerator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812 (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, RuntimeObject* ___0_routine, const RuntimeMethod* method) ;
// System.Boolean GameManager::get_NeedDialogueBoxHint()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_NeedDialogueBoxHint_m2D72B960A1B248627A87A7CF0F5F5E8728C67C55_inline (const RuntimeMethod* method) ;
// System.Collections.IEnumerator UIManager::HintDialogue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_HintDialogue_m0C7E9551F4E5A95C2F915FF40632B080F9ADEA25 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// System.Void UIManager/<TypeSentence>d__57::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTypeSentenceU3Ed__57__ctor_m9895C4EF13ED39F948375519C39C50E51E171E5A (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void UIManager/<FinishSentence>d__58::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CFinishSentenceU3Ed__58__ctor_m281085BF5E276CFBBC46C07932620E72779666CB (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<IRunner>()
inline RuntimeObject* GameObject_GetComponent_TisIRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_m4917A327E1DA277C56EA59748DD449F82FF7B190 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
// System.Void UnityEngine.Debug::Log(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.Transform::GetChild(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* Transform_GetChild_mE686DF0C7AAC1F7AEF356967B1C04D8B8E240EAF (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponentInChildren<TMPro.TextMeshProUGUI>()
inline TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* Component_GetComponentInChildren_TisTextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957_m60A1B193FDBBFB3719065622DB5E0BB21CA4ABDC (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponentInChildren_TisRuntimeObject_mE483A27E876DE8E4E6901D6814837F81D7C42F65_gshared)(__this, method);
}
// System.Int32 GameManager::get_AcquiredStars()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline (const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m093934F71A9B351911EE46311674ED463B180006 (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, String_t* ___3_str3, const RuntimeMethod* method) ;
// System.Int32 GameManager::get_CurrentScore()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_CurrentScore_mCFD308B1545586CD81E7B5051BFE261008BD484C_inline (const RuntimeMethod* method) ;
// System.Void UIManager::ResetSliders()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ResetSliders_m8CA4B0C1EAAE88785229FE0E77936A2CB6C9B03D (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// System.Void UIManager::ResetStars()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ResetStars_m1E94D905F7430356C2D6B9F6F6FBB7ABBE6E14F4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// System.Int32 GameManager::get_MaxStages()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GameManager_get_MaxStages_mB5F198316B9492B632EDB0669F1C594EF7DF3BE8 (const RuntimeMethod* method) ;
// Answer GameManager::get_StageAnswerQuality()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_StageAnswerQuality_mCD07E8FED832C6E4AA0E6C875D02939D2CD92E16_inline (const RuntimeMethod* method) ;
// System.Void UIManager::Assessment(Answer)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_Assessment_m4A7BC4F058D63345692A7C34597E0FC9C8048B34 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_answer, const RuntimeMethod* method) ;
// System.Collections.IEnumerator UIManager::BankStars(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_BankStars_m30DEC5BDD35083775406BB805945F715F5DF6A21 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_stars, const RuntimeMethod* method) ;
// StageDialogue GameManager::get_CurrentStageDialogue()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* GameManager_get_CurrentStageDialogue_m298FEF5012933892CF97212C2D056F0252EA3BA7_inline (const RuntimeMethod* method) ;
// System.Void DialogueManager::NextAnswer(StageDialogue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DialogueManager_NextAnswer_mD45D15A36CDB58F3B18C915C2EC8F3B3D1790D86 (DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* __this, StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* ___0_stageDialogue, const RuntimeMethod* method) ;
// System.Void UIManager/<BankStars>d__64::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CBankStarsU3Ed__64__ctor_m1B9DE110E86825630F79A735AA8107BBDC94B4F1 (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.GameObject::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Mathf::Min(System.Int32,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Mathf_Min_m888083F74FF5655778F0403BB5E9608BEFDEA8CB_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
// System.Collections.Generic.List`1/Enumerator<T> System.Collections.Generic.List`1<UnityEngine.GameObject>::GetEnumerator()
inline Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60 List_1_GetEnumerator_mA843D26C63E5963415DFCA6E49DFA27AFD9C75E8 (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60 (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1/Enumerator<UnityEngine.GameObject>::Dispose()
inline void Enumerator_Dispose_m07D362A07C19B36C2FD1B4DC79DD99903D4DA95D (Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60*, const RuntimeMethod*))Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared)(__this, method);
}
// T System.Collections.Generic.List`1/Enumerator<UnityEngine.GameObject>::get_Current()
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Enumerator_get_Current_m7236EBE1CFCB6533F96E030500D322B13D0CA5A4_inline (Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60* __this, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
// UnityEngine.GameObject UnityEngine.GameObject::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* GameObject_get_gameObject_m0878015B8CF7F5D432B583C187725810D27B57DC (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Object::Destroy(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_obj, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1/Enumerator<UnityEngine.GameObject>::MoveNext()
inline bool Enumerator_MoveNext_m96F4B0BD0A5485C8E8CC57D961DF6F1FA256AF27 (Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.GameObject>::Clear()
inline void List_1_Clear_m32D399BDD753B5BD6CE27560249096418F3F0867_inline (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, const RuntimeMethod*))List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline)(__this, method);
}
// T UnityEngine.Object::Instantiate<UnityEngine.GameObject>(T,UnityEngine.Transform)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_original, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___1_parent, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1*, const RuntimeMethod*))Object_Instantiate_TisRuntimeObject_m75BF3B0A3747B60491845FA41612FE7F795F0A59_gshared)(___0_original, ___1_parent, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.GameObject>::Add(T)
inline void List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_inline (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void UIManager::ToggleCompassionateStars(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, bool ___0_toggle, const RuntimeMethod* method) ;
// System.Void UIManager::ResetCompassionateStars()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.UI.Slider::set_maxValue(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Slider_set_maxValue_m43F3BF47C6D7063D80C578FD9B95AD88494203BE (Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Inequality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Animation::Play()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Animation_Play_m717560D2F561D9E12583AB3B435E6BC996448C3E (Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* __this, const RuntimeMethod* method) ;
// System.Void GameManager::OpenMainMenu()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_OpenMainMenu_mD699596D765A018D44AF07793DF53DAACE6E18DE (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::Invoke(System.String,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour_Invoke_mF724350C59362B0F1BFE26383209A274A29A63FB (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, float ___1_time, const RuntimeMethod* method) ;
// System.Void UnityEngine.Color::.ctor(System.Single,System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* __this, float ___0_r, float ___1_g, float ___2_b, float ___3_a, const RuntimeMethod* method) ;
// System.Collections.IEnumerator UIManager::EndCreditsRoll()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_EndCreditsRoll_m8C0F335EBD2B6222A711321E98D94584B1E1C1A4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// System.Void GameManager::ResetDefaultSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_ResetDefaultSettings_mF4FEE9BB6A9C74DC67FFADA42B0170BE36BA604E (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) ;
// System.Void UIManager/<MainMenuReset>d__71::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CMainMenuResetU3Ed__71__ctor_m851F0981FCD37DFC2AE2E617FE5DC67486FD8F2F (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void UIManager/<EndCreditsRoll>d__72::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CEndCreditsRollU3Ed__72__ctor_m807C81428DCAB66E2B3F28CDDE747FFAC81961DF (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void UIManager/<HintDialogue>d__73::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CHintDialogueU3Ed__73__ctor_m94B102F2B01586664F5DC32D7986BF0494BF03C7 (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Boolean GameManager::get_IsGameOver()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsGameOver_mF865E823B3B8F11883D33D15152D2680CE20AD33_inline (const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Int32>::Invoke(T)
inline void Action_1_Invoke_mAC3C34BA1905AB5B79E483CD9BB082B7D667F703_inline (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* __this, int32_t ___0_obj, const RuntimeMethod* method)
{
	((  void (*) (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*, int32_t, const RuntimeMethod*))Action_1_Invoke_mAC3C34BA1905AB5B79E483CD9BB082B7D667F703_gshared_inline)(__this, ___0_obj, method);
}
// System.Void GameManager::UpdateGameState(GameState)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_UpdateGameState_m74D3EC2581A497E87BF55A0C0EA6F17F1BB17D03 (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, int32_t ___0_newState, const RuntimeMethod* method) ;
// System.Void GameManager::SetupNextStage()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_SetupNextStage_m637E2D17484002DA036867261EAB2528367C64C1 (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) ;
// System.Void DialogueManager::EndDialogue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DialogueManager_EndDialogue_m362F7B00007371C46591FE75AC073DA523731854 (DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* __this, const RuntimeMethod* method) ;
// System.Void DialogueManager::NextQuery(StageDialogue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DialogueManager_NextQuery_m6BF8E6FE72B38B88DB8F95D628088E2C81DE9968 (DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* __this, StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* ___0_stageDialogue, const RuntimeMethod* method) ;
// System.Void GameManager::CloseMainMenu()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_CloseMainMenu_m4A4CC2BBCD9C4560DE1CC9638F8305FE6C4AC000 (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) ;
// System.Void UIManager::OnContinueButtonClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnContinueButtonClick_mAA42C08726C56D19843960EA4F8C45D7A8BFD6F4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Behaviour::get_enabled()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Behaviour_get_enabled_mAAC9F15E9EBF552217A5AE2681589CC0BFA300C1 (Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA* __this, const RuntimeMethod* method) ;
// System.Void GameManager::set_IsStageMenuOpen(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsStageMenuOpen_m8A712BA74947AD95FA3444508E8533F8644F3CAD_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void SaveData::ClearAllSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SaveData_ClearAllSettings_m52625A0058652FBE5321F0E0BC7D06DE3269919C (const RuntimeMethod* method) ;
// System.Void GameManager::LoadDefaultSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_LoadDefaultSettings_mD2A1CA3417352CF5B3789B64A7AFD4B5BC22825B (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) ;
// System.Void UIManager::OnQuitToMenu()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnQuitToMenu_mF966FF59A27A00115B39EE76A8A917829E43B3B5 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// UnityEngine.Color UnityEngine.Color::get_black()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Color_tD001788D726C3A7F1379BEED0260B9591F440C1F Color_get_black_mB50217951591A045844C61E7FF31EEE3FEF16737_inline (const RuntimeMethod* method) ;
// System.Void GameManager::QuitToMenu()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameManager_QuitToMenu_m8BD0046A2E4FE4598B5558DA32F8258FFC67E8F6 (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) ;
// System.Collections.IEnumerator UIManager::MainMenuReset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_MainMenuReset_m072F87EE4F77D62EA13AA42B5D1E630B425A1EB4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.WaitForSecondsRealtime::.ctor(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WaitForSecondsRealtime__ctor_mBFC1E4F0E042D5EC6E7EEB211A2FE5193A8F6D6F (WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* __this, float ___0_time, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.GameObject>::.ctor()
inline void List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void UnityEngine.WaitForSeconds::.ctor(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* __this, float ___0_seconds, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Char[] System.String::ToCharArray()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* String_ToCharArray_m0699A92AA3E744229EF29CB9D943C47DF4FE5B46 (String_t* __this, const RuntimeMethod* method) ;
// System.String System.Char::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Char_ToString_m2A308731F9577C06AF3C0901234E2EAC8327410C (Il2CppChar* __this, const RuntimeMethod* method) ;
// System.Void System.NotSupportedException::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.AudioSource::Play()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioSource_Play_m95DF07111C61D0E0F00257A00384D31531D590C3 (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, const RuntimeMethod* method) ;
// UnityEngine.AnimationClip UnityEngine.Animation::GetClip(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712* Animation_GetClip_m566FFEC9EA0EA79DB1BAC0B79F37CD6A3A85C296 (Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* __this, String_t* ___0_name, const RuntimeMethod* method) ;
// System.Single UnityEngine.AnimationClip::get_length()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AnimationClip_get_length_mAD91A1C134662285F26886489AC2D8E0EC79AF41 (AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712* __this, const RuntimeMethod* method) ;
// System.Void GameManager::set_NeedDialogueBoxHint(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_NeedDialogueBoxHint_m0B8BBB24C02B9D699559C94865BD6C63667F5884_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void System.Array::Clear(System.Array,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ButtonToggle::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_Awake_m0426A7AFA49CC9788EFD87FEDD2A7F86CB198B53 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// switch (_buttonType)
		int32_t L_0 = __this->____buttonType_4;
		V_0 = L_0;
		int32_t L_1 = V_0;
		switch (L_1)
		{
			case 0:
			{
				goto IL_001f;
			}
			case 1:
			{
				goto IL_002c;
			}
			case 2:
			{
				goto IL_0039;
			}
			case 3:
			{
				goto IL_0046;
			}
		}
	}
	{
		goto IL_0051;
	}

IL_001f:
	{
		// _isEnabled = GameManager.IsAudioEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = GameManager_get_IsAudioEnabled_m89BB8BC284997DB0FC96A9405C1B035E984C72E1_inline(NULL);
		__this->____isEnabled_7 = L_2;
		// break;
		goto IL_0051;
	}

IL_002c:
	{
		// _isEnabled = GameManager.IsMusicEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = GameManager_get_IsMusicEnabled_mD149DDFF2ABF807F087BB4D6DA0625F0C8D55065_inline(NULL);
		__this->____isEnabled_7 = L_3;
		// break;
		goto IL_0051;
	}

IL_0039:
	{
		// _isEnabled = GameManager.IsHapticEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = GameManager_get_IsHapticEnabled_m64A912E276482E96D33E589E15B102FA68140AC5_inline(NULL);
		__this->____isEnabled_7 = L_4;
		// break;
		goto IL_0051;
	}

IL_0046:
	{
		// _isEnabled = GameManager.IsTutorialsEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_5;
		L_5 = GameManager_get_IsTutorialsEnabled_m2DCFC9B855219403A47C511B56C3E33EF7C35314_inline(NULL);
		__this->____isEnabled_7 = L_5;
	}

IL_0051:
	{
		// UpdateImage();
		ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73(__this, NULL);
		// }
		return;
	}
}
// System.Void ButtonToggle::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_OnEnable_m0724479FF2A9AFB8DB7FF1BC74CBE5BBC459C0B7 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ButtonToggle_UpdateTutorialToggle_m17E2962CFBCA6833FF0830840AAE3A717434C949_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GameManager.OnDisableTutorials += UpdateTutorialToggle;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnDisableTutorials_80;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_1 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_1, __this, (intptr_t)((void*)ButtonToggle_UpdateTutorialToggle_m17E2962CFBCA6833FF0830840AAE3A717434C949_RuntimeMethod_var), NULL);
		Delegate_t* L_2;
		L_2 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_0, L_1, NULL);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnDisableTutorials_80 = ((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_2, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnDisableTutorials_80), (void*)((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_2, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var)));
		// }
		return;
	}
}
// System.Void ButtonToggle::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_OnDisable_m38BE68124751FB35CBB9280D7CCFEFBE2CFEA9BF (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ButtonToggle_UpdateTutorialToggle_m17E2962CFBCA6833FF0830840AAE3A717434C949_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GameManager.OnDisableTutorials -= UpdateTutorialToggle;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnDisableTutorials_80;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_1 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_1, __this, (intptr_t)((void*)ButtonToggle_UpdateTutorialToggle_m17E2962CFBCA6833FF0830840AAE3A717434C949_RuntimeMethod_var), NULL);
		Delegate_t* L_2;
		L_2 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_0, L_1, NULL);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnDisableTutorials_80 = ((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_2, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnDisableTutorials_80), (void*)((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_2, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var)));
		// }
		return;
	}
}
// System.Void ButtonToggle::Toggle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_Toggle_mC2AF8D3392D320EA1C3617A41BDEFB7324B9EC05 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* G_B2_0 = NULL;
	ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* G_B3_1 = NULL;
	{
		// _isEnabled = _isEnabled? false : true;
		bool L_0 = __this->____isEnabled_7;
		G_B1_0 = __this;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_000c;
		}
	}
	{
		G_B3_0 = 1;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_000c:
	{
		G_B3_0 = 0;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		NullCheck(G_B3_1);
		G_B3_1->____isEnabled_7 = (bool)G_B3_0;
		// }
		return;
	}
}
// System.Void ButtonToggle::UpdateImage()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	{
		// _enabledImage.enabled = _isEnabled;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_0 = __this->____enabledImage_5;
		bool L_1 = __this->____isEnabled_7;
		NullCheck(L_0);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_0, L_1, NULL);
		// _disabledImage.enabled = !_isEnabled;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_2 = __this->____disabledImage_6;
		bool L_3 = __this->____isEnabled_7;
		NullCheck(L_2);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_2, (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0), NULL);
		// }
		return;
	}
}
// System.Void ButtonToggle::UpdateTutorialToggle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_UpdateTutorialToggle_m17E2962CFBCA6833FF0830840AAE3A717434C949 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (_buttonType != ButtonType.Tutorials) { return; }
		int32_t L_0 = __this->____buttonType_4;
		if ((((int32_t)L_0) == ((int32_t)3)))
		{
			goto IL_000a;
		}
	}
	{
		// if (_buttonType != ButtonType.Tutorials) { return; }
		return;
	}

IL_000a:
	{
		// _isEnabled = GameManager.IsTutorialsEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = GameManager_get_IsTutorialsEnabled_m2DCFC9B855219403A47C511B56C3E33EF7C35314_inline(NULL);
		__this->____isEnabled_7 = L_1;
		// UpdateImage();
		ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73(__this, NULL);
		// }
		return;
	}
}
// System.Void ButtonToggle::OnAudioMute()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_OnAudioMute_m833C9A1DE3B48C280E4AD0B20A06028D53CD18E2 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Toggle();
		ButtonToggle_Toggle_mC2AF8D3392D320EA1C3617A41BDEFB7324B9EC05(__this, NULL);
		// UpdateImage();
		ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73(__this, NULL);
		// AudioManager.Instance.MuteAudio(_isEnabled);
		AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613* L_0 = ((AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_StaticFields*)il2cpp_codegen_static_fields_for(AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var))->___Instance_26;
		bool L_1 = __this->____isEnabled_7;
		NullCheck(L_0);
		AudioManager_MuteAudio_m57EDEBFF009C988B17D3B3A6BBCF0358DD5868AB(L_0, L_1, NULL);
		// GameManager.IsAudioEnabled = _isEnabled;
		bool L_2 = __this->____isEnabled_7;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsAudioEnabled_mF8233819F6804D705F704141A489FC0E56D97D62_inline(L_2, NULL);
		// }
		return;
	}
}
// System.Void ButtonToggle::OnMusicMute()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_OnMusicMute_m55C60B2319138C371F4C0BFBF49DC6A3F0025F08 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Toggle();
		ButtonToggle_Toggle_mC2AF8D3392D320EA1C3617A41BDEFB7324B9EC05(__this, NULL);
		// UpdateImage();
		ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73(__this, NULL);
		// AudioManager.Instance.MuteMusic(_isEnabled);
		AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613* L_0 = ((AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_StaticFields*)il2cpp_codegen_static_fields_for(AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var))->___Instance_26;
		bool L_1 = __this->____isEnabled_7;
		NullCheck(L_0);
		AudioManager_MuteMusic_m9173DCB0C32C8E9D16D1618B08A1E25614B11C4B(L_0, L_1, NULL);
		// GameManager.IsMusicEnabled = _isEnabled;
		bool L_2 = __this->____isEnabled_7;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsMusicEnabled_m32A5D2E12A9CD4D37B4DE1C06A1B79F53759575D_inline(L_2, NULL);
		// }
		return;
	}
}
// System.Void ButtonToggle::OnHapticDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_OnHapticDisable_m9DEFDFAD6C6B18C8B905DA57AAF944572AB218C2 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Toggle();
		ButtonToggle_Toggle_mC2AF8D3392D320EA1C3617A41BDEFB7324B9EC05(__this, NULL);
		// UpdateImage();
		ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73(__this, NULL);
		// GameManager.IsHapticEnabled = _isEnabled;
		bool L_0 = __this->____isEnabled_7;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsHapticEnabled_m32528E40700F774A8501FA6E2FDF22FE25F907D7_inline(L_0, NULL);
		// }
		return;
	}
}
// System.Void ButtonToggle::OnTutorialsToggle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle_OnTutorialsToggle_m811AFA4D47E8FA37AE608C1E1E0B560720C64139 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Toggle();
		ButtonToggle_Toggle_mC2AF8D3392D320EA1C3617A41BDEFB7324B9EC05(__this, NULL);
		// UpdateImage();
		ButtonToggle_UpdateImage_m5008DCD7A6C419210B93F309419A87F64540BB73(__this, NULL);
		// GameManager.IsTutorialsEnabled = _isEnabled;
		bool L_0 = __this->____isEnabled_7;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsTutorialsEnabled_m5F855CEEE242B7D1F3181362EAC2C6CF50E589E1_inline(L_0, NULL);
		// }
		return;
	}
}
// System.Void ButtonToggle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonToggle__ctor_mD0FF1D13BE2813DF9072F87340851D4B92F18FF8 (ButtonToggle_tDA2C79FC7B2CFF75C18FB7E5C3CCF92430D38B8D* __this, const RuntimeMethod* method) 
{
	{
		// private bool _isEnabled = true;
		__this->____isEnabled_7 = (bool)1;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_Awake_m376536BDFC736C42450178E0FA5F4C8703E28FE6 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _activeSlider = _speedSliders[0];
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_0 = __this->____speedSliders_9;
		NullCheck(L_0);
		int32_t L_1 = 0;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		__this->____activeSlider_46 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____activeSlider_46), (void*)L_2);
		// _compassionateStars.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = __this->____compassionateStars_12;
		NullCheck(L_3);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_3, (bool)0, NULL);
		// _lifetimeStarsAmountMenu.text = GameManager.HighScore.ToString();
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_4 = __this->____lifetimeStarsAmountMenu_7;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		String_t* L_5;
		L_5 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___HighScore_93), NULL);
		NullCheck(L_4);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_4, L_5);
		// _topCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_6 = __this->____topCanvas_15;
		NullCheck(L_6);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_6, (bool)0, NULL);
		// _stageCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_7 = __this->____stageCanvas_14;
		NullCheck(L_7);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_7, (bool)0, NULL);
		// _menuSettingsCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_8 = __this->____menuSettingsCanvas_17;
		NullCheck(L_8);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_8, (bool)0, NULL);
		// _blackScreenStart.enabled = true;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_9 = __this->____blackScreenStart_29;
		NullCheck(L_9);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_9, (bool)1, NULL);
		// _blackScreenEnd.enabled = false;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_10 = __this->____blackScreenEnd_30;
		NullCheck(L_10);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_10, (bool)0, NULL);
		// _loadingText.enabled = true;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_11 = __this->____loadingText_28;
		NullCheck(L_11);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_11, (bool)1, NULL);
		// _mainPage.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_12 = __this->____mainPage_21;
		NullCheck(L_12);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_12, (bool)1, NULL);
		// _backPage.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_13 = __this->____backPage_22;
		NullCheck(L_13);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_13, (bool)0, NULL);
		// _endCreditsObj.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14 = __this->____endCreditsObj_31;
		NullCheck(L_14);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_14, (bool)0, NULL);
		// _newHighScore.enabled = false;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_15 = __this->____newHighScore_8;
		NullCheck(L_15);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_15, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnEnable_m0FA2D64AA02FAC4674ADE02D320838EA43EDEEFC (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Row_t1EE15C0BD0EC4753FA23C96884DE1DE136C4DB19_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_AssignDialogueBox_mA02ACC08EF1AE90E9BF2FCDB6B88848362E6948F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_BeginStage_m9765DBBC150EE6472BEFD406A5AE8DD387EB77AC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_BlackScreenFadeIn_mA8C7A7488676524CC74004C93A22A6C255B2DC5F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_BlackScreenFadeOut_mA74743737254BACC2CC126AB239416EAA19FD143_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_EndStage_mBB8377AFDBC3E9C61A70CF7CCCBD4737BD537270_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_GainStar_mC2B8C93E19707CD2CC1DA97214AFE05B52B0836A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_HideDialogueBox_mF51F524D06B33CD86E91434FCA908277DCADA981_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_MainMenu_m266054608AA5ECFD724D14077C1800FC85CD5673_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_UpdateCompassionateSlider_m1EAC1195B36B29BCA99A40352F55DFD1EFF9769C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_UpdateDialogueBox_mA80B91F523DE326AADA4C78971738159CCB0C0E6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_UpdateSpeedBonus_mC3095028203E1D1AC7AD695164B5B727CD50DB5C_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GameManager.OnStarBonusChanged += UpdateSpeedBonus;
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_0 = (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*)il2cpp_codegen_object_new(Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87(L_0, __this, (intptr_t)((void*)UIManager_UpdateSpeedBonus_mC3095028203E1D1AC7AD695164B5B727CD50DB5C_RuntimeMethod_var), NULL);
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_add_OnStarBonusChanged_m3E2F922C8D11C1400DF7524BA2E3D62C76F1E6C5(L_0, NULL);
		// GameManager.OnCompassionateChargeUp += UpdateCompassionateSlider;
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_1 = (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*)il2cpp_codegen_object_new(Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87(L_1, __this, (intptr_t)((void*)UIManager_UpdateCompassionateSlider_m1EAC1195B36B29BCA99A40352F55DFD1EFF9769C_RuntimeMethod_var), NULL);
		GameManager_add_OnCompassionateChargeUp_m2052CD2BBF7224CC67CB8C3B6904783244628C77(L_1, NULL);
		// GameManager.OnCompassionateStarsToggle += ToggleCompassionateStars;
		Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* L_2 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnCompassionateStarsToggle_77;
		Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* L_3 = (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*)il2cpp_codegen_object_new(Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501(L_3, __this, (intptr_t)((void*)UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67_RuntimeMethod_var), NULL);
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnCompassionateStarsToggle_77 = ((Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*)Castclass((RuntimeObject*)L_4, Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnCompassionateStarsToggle_77), (void*)((Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*)Castclass((RuntimeObject*)L_4, Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var)));
		// GameManager.OnCompassionateStarsReset += ResetCompassionateStars;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_5 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_5, __this, (intptr_t)((void*)UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC_RuntimeMethod_var), NULL);
		GameManager_add_OnCompassionateStarsReset_m0829D0535935B26679FAD278D2A738279455403C(L_5, NULL);
		// GameManager.OnRunnerSpawned += AssignDialogueBox;
		Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C* L_6 = (Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C*)il2cpp_codegen_object_new(Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		Action_1__ctor_m3FA37AFA5AAB09F49F9C00A7D5B2A5F3D83CBB01(L_6, __this, (intptr_t)((void*)UIManager_AssignDialogueBox_mA02ACC08EF1AE90E9BF2FCDB6B88848362E6948F_RuntimeMethod_var), NULL);
		GameManager_add_OnRunnerSpawned_mABA868571A5C4B0AEA6E4C9CD6FA6F3A9F8F30B1(L_6, NULL);
		// GameManager.OnStageEnd += EndStage;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_7 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_7, __this, (intptr_t)((void*)UIManager_EndStage_mBB8377AFDBC3E9C61A70CF7CCCBD4737BD537270_RuntimeMethod_var), NULL);
		GameManager_add_OnStageEnd_m6762C7BA8C01352592448CC95F7A5DD8E40986B3(L_7, NULL);
		// GameManager.OnStateChanged += BeginStage;
		Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978* L_8 = (Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978*)il2cpp_codegen_object_new(Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		Action_1__ctor_mBCE4C560DFFB6626B4C265665FDFE6B1A1F1E7D4(L_8, __this, (intptr_t)((void*)UIManager_BeginStage_m9765DBBC150EE6472BEFD406A5AE8DD387EB77AC_RuntimeMethod_var), NULL);
		GameManager_add_OnStateChanged_m1B142A23151688D2673259C2F39443C0E111D96D(L_8, NULL);
		// GameManager.OnMainMenuOpen += MainMenu;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_9 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_9);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_9, __this, (intptr_t)((void*)UIManager_MainMenu_m266054608AA5ECFD724D14077C1800FC85CD5673_RuntimeMethod_var), NULL);
		GameManager_add_OnMainMenuOpen_m4ED8B1035649550741C350E2BD25C72904D83484(L_9, NULL);
		// GameManager.OnStarGained += GainStar;
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_10 = (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*)il2cpp_codegen_object_new(Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87(L_10, __this, (intptr_t)((void*)UIManager_GainStar_mC2B8C93E19707CD2CC1DA97214AFE05B52B0836A_RuntimeMethod_var), NULL);
		GameManager_add_OnStarGained_mB8875BB8EF7DA5D0A547AA70F0713A020A4BBAFE(L_10, NULL);
		// GameManager.OnGameOver += BlackScreenFadeIn;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_11 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_11, __this, (intptr_t)((void*)UIManager_BlackScreenFadeIn_mA8C7A7488676524CC74004C93A22A6C255B2DC5F_RuntimeMethod_var), NULL);
		GameManager_add_OnGameOver_m3F4A6D0778A05C2401E44CA3CCBCB1F0B158F105(L_11, NULL);
		// DialogueManager.OnNextSentence += UpdateDialogueBox;
		Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A* L_12 = (Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A*)il2cpp_codegen_object_new(Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A_il2cpp_TypeInfo_var);
		NullCheck(L_12);
		Action_1__ctor_m9DC2953C55C4D7D4B7BEFE03D84DA1F9362D652C(L_12, __this, (intptr_t)((void*)UIManager_UpdateDialogueBox_mA80B91F523DE326AADA4C78971738159CCB0C0E6_RuntimeMethod_var), NULL);
		DialogueManager_add_OnNextSentence_m68AA8DA5C147EC06070D33642D194332649466D3(L_12, NULL);
		// DialogueManager.OnDialogueEnd += HideDialogueBox;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_13 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_13);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_13, __this, (intptr_t)((void*)UIManager_HideDialogueBox_mF51F524D06B33CD86E91434FCA908277DCADA981_RuntimeMethod_var), NULL);
		DialogueManager_add_OnDialogueEnd_mB5C9653BE9E133506EDF81FC05DAE4750D441E71(L_13, NULL);
		// Row.OnFirstRowsReady += BlackScreenFadeOut;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_14 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_14);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_14, __this, (intptr_t)((void*)UIManager_BlackScreenFadeOut_mA74743737254BACC2CC126AB239416EAA19FD143_RuntimeMethod_var), NULL);
		il2cpp_codegen_runtime_class_init_inline(Row_t1EE15C0BD0EC4753FA23C96884DE1DE136C4DB19_il2cpp_TypeInfo_var);
		Row_add_OnFirstRowsReady_m791BA7EA4FBECF36F12C73E1644980C58C437E29(L_14, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnDisable_m58AFC5567CCF17A7B97BC062F7DEB2DF0C4D8CE7 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Row_t1EE15C0BD0EC4753FA23C96884DE1DE136C4DB19_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_AssignDialogueBox_mA02ACC08EF1AE90E9BF2FCDB6B88848362E6948F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_BeginStage_m9765DBBC150EE6472BEFD406A5AE8DD387EB77AC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_BlackScreenFadeIn_mA8C7A7488676524CC74004C93A22A6C255B2DC5F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_BlackScreenFadeOut_mA74743737254BACC2CC126AB239416EAA19FD143_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_EndStage_mBB8377AFDBC3E9C61A70CF7CCCBD4737BD537270_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_GainStar_mC2B8C93E19707CD2CC1DA97214AFE05B52B0836A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_HideDialogueBox_mF51F524D06B33CD86E91434FCA908277DCADA981_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_MainMenu_m266054608AA5ECFD724D14077C1800FC85CD5673_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_UpdateCompassionateSlider_m1EAC1195B36B29BCA99A40352F55DFD1EFF9769C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_UpdateDialogueBox_mA80B91F523DE326AADA4C78971738159CCB0C0E6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIManager_UpdateSpeedBonus_mC3095028203E1D1AC7AD695164B5B727CD50DB5C_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GameManager.OnStarBonusChanged -= UpdateSpeedBonus;
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_0 = (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*)il2cpp_codegen_object_new(Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87(L_0, __this, (intptr_t)((void*)UIManager_UpdateSpeedBonus_mC3095028203E1D1AC7AD695164B5B727CD50DB5C_RuntimeMethod_var), NULL);
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_remove_OnStarBonusChanged_m9DD0694B3CCED09AB33E710C39A95657694EC49B(L_0, NULL);
		// GameManager.OnCompassionateChargeUp -= UpdateCompassionateSlider;
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_1 = (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*)il2cpp_codegen_object_new(Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87(L_1, __this, (intptr_t)((void*)UIManager_UpdateCompassionateSlider_m1EAC1195B36B29BCA99A40352F55DFD1EFF9769C_RuntimeMethod_var), NULL);
		GameManager_remove_OnCompassionateChargeUp_m038899309B12D97F39DCA9E68F34BB8A5A74590A(L_1, NULL);
		// GameManager.OnCompassionateStarsToggle -= ToggleCompassionateStars;
		Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* L_2 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnCompassionateStarsToggle_77;
		Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* L_3 = (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*)il2cpp_codegen_object_new(Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501(L_3, __this, (intptr_t)((void*)UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67_RuntimeMethod_var), NULL);
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnCompassionateStarsToggle_77 = ((Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*)Castclass((RuntimeObject*)L_4, Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnCompassionateStarsToggle_77), (void*)((Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*)Castclass((RuntimeObject*)L_4, Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var)));
		// GameManager.OnCompassionateStarsReset -= ResetCompassionateStars;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_5 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_5, __this, (intptr_t)((void*)UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC_RuntimeMethod_var), NULL);
		GameManager_remove_OnCompassionateStarsReset_m7FA693CF2CB8916CC9AE4758576D6A8788033C10(L_5, NULL);
		// GameManager.OnRunnerSpawned -= AssignDialogueBox;
		Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C* L_6 = (Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C*)il2cpp_codegen_object_new(Action_1_tFF0F3D982F6CEB68CBA322555CBBEE6AE1D2519C_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		Action_1__ctor_m3FA37AFA5AAB09F49F9C00A7D5B2A5F3D83CBB01(L_6, __this, (intptr_t)((void*)UIManager_AssignDialogueBox_mA02ACC08EF1AE90E9BF2FCDB6B88848362E6948F_RuntimeMethod_var), NULL);
		GameManager_remove_OnRunnerSpawned_mB4E63D8A77EA90664FBB93E96712CE33796E7EBC(L_6, NULL);
		// GameManager.OnStageEnd -= EndStage;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_7 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_7, __this, (intptr_t)((void*)UIManager_EndStage_mBB8377AFDBC3E9C61A70CF7CCCBD4737BD537270_RuntimeMethod_var), NULL);
		GameManager_remove_OnStageEnd_m6F1681650AB40E8412FAD7320276742D0BAE4159(L_7, NULL);
		// GameManager.OnStateChanged -= BeginStage;
		Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978* L_8 = (Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978*)il2cpp_codegen_object_new(Action_1_t97EB52F89C98CE3C1B240F2A8FA7F1168E9C2978_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		Action_1__ctor_mBCE4C560DFFB6626B4C265665FDFE6B1A1F1E7D4(L_8, __this, (intptr_t)((void*)UIManager_BeginStage_m9765DBBC150EE6472BEFD406A5AE8DD387EB77AC_RuntimeMethod_var), NULL);
		GameManager_remove_OnStateChanged_mBE73BDEFC471BB001E101A182EAB87BF62699DEF(L_8, NULL);
		// GameManager.OnMainMenuOpen -= MainMenu;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_9 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_9);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_9, __this, (intptr_t)((void*)UIManager_MainMenu_m266054608AA5ECFD724D14077C1800FC85CD5673_RuntimeMethod_var), NULL);
		GameManager_remove_OnMainMenuOpen_mBAFB451D7582B215B4D888145CE925F6B784FB3D(L_9, NULL);
		// GameManager.OnStarGained -= GainStar;
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_10 = (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404*)il2cpp_codegen_object_new(Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		Action_1__ctor_m1BA854F3F4319EA4A4294DDFDA21C395B8D0FF87(L_10, __this, (intptr_t)((void*)UIManager_GainStar_mC2B8C93E19707CD2CC1DA97214AFE05B52B0836A_RuntimeMethod_var), NULL);
		GameManager_remove_OnStarGained_mDD44B3EBF6FFE7EB1823BA7D67735DCDE1D0D27D(L_10, NULL);
		// GameManager.OnGameOver -= BlackScreenFadeIn;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_11 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_11, __this, (intptr_t)((void*)UIManager_BlackScreenFadeIn_mA8C7A7488676524CC74004C93A22A6C255B2DC5F_RuntimeMethod_var), NULL);
		GameManager_remove_OnGameOver_mE474DA270549E34052B3B285CC6BD07F94BB3743(L_11, NULL);
		// DialogueManager.OnNextSentence -= UpdateDialogueBox;
		Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A* L_12 = (Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A*)il2cpp_codegen_object_new(Action_1_t3CB5D1A819C3ED3F99E9E39F890F18633253949A_il2cpp_TypeInfo_var);
		NullCheck(L_12);
		Action_1__ctor_m9DC2953C55C4D7D4B7BEFE03D84DA1F9362D652C(L_12, __this, (intptr_t)((void*)UIManager_UpdateDialogueBox_mA80B91F523DE326AADA4C78971738159CCB0C0E6_RuntimeMethod_var), NULL);
		DialogueManager_remove_OnNextSentence_mDE42E6FEFC3ED09395FA3227264EEEDC32A0A8E4(L_12, NULL);
		// DialogueManager.OnDialogueEnd -= HideDialogueBox;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_13 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_13);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_13, __this, (intptr_t)((void*)UIManager_HideDialogueBox_mF51F524D06B33CD86E91434FCA908277DCADA981_RuntimeMethod_var), NULL);
		DialogueManager_remove_OnDialogueEnd_m42E419EFBB96C5BADCBE4488F9A11CDC8BB462D2(L_13, NULL);
		// Row.OnFirstRowsReady -= BlackScreenFadeOut;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_14 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_14);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_14, __this, (intptr_t)((void*)UIManager_BlackScreenFadeOut_mA74743737254BACC2CC126AB239416EAA19FD143_RuntimeMethod_var), NULL);
		il2cpp_codegen_runtime_class_init_inline(Row_t1EE15C0BD0EC4753FA23C96884DE1DE136C4DB19_il2cpp_TypeInfo_var);
		Row_remove_OnFirstRowsReady_mEF39E4D2A1EBB5E603FF0AB437DFF277AF665905(L_14, NULL);
		// }
		return;
	}
}
// System.Void UIManager::UpdateSpeedBonus(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_UpdateSpeedBonus_mC3095028203E1D1AC7AD695164B5B727CD50DB5C (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _activeSlider.value = value % (GameManager.RequiredStars * 100);
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_0 = __this->____activeSlider_46;
		int32_t L_1 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline(NULL);
		NullCheck(L_0);
		VirtualActionInvoker1< float >::Invoke(47 /* System.Void UnityEngine.UI.Slider::set_value(System.Single) */, L_0, ((float)((int32_t)(L_1%((int32_t)il2cpp_codegen_multiply(L_2, ((int32_t)100)))))));
		// }
		return;
	}
}
// System.Void UIManager::ToggleCompassionateStars(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, bool ___0_toggle, const RuntimeMethod* method) 
{
	{
		// _compassionateStars.SetActive(toggle);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->____compassionateStars_12;
		bool L_1 = ___0_toggle;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, L_1, NULL);
		// _requiredStars.SetActive(!toggle);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = __this->____requiredStars_10;
		bool L_3 = ___0_toggle;
		NullCheck(L_2);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_2, (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0), NULL);
		// }
		return;
	}
}
// System.Void UIManager::ResetCompassionateStars()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// for (int i = 0; i < 3; i++)
		V_0 = 0;
		goto IL_001a;
	}

IL_0004:
	{
		// _compassionateSliders[i].value = 0;
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_0 = __this->____compassionateSliders_13;
		int32_t L_1 = V_0;
		NullCheck(L_0);
		int32_t L_2 = L_1;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		VirtualActionInvoker1< float >::Invoke(47 /* System.Void UnityEngine.UI.Slider::set_value(System.Single) */, L_3, (0.0f));
		// for (int i = 0; i < 3; i++)
		int32_t L_4 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_4, 1));
	}

IL_001a:
	{
		// for (int i = 0; i < 3; i++)
		int32_t L_5 = V_0;
		if ((((int32_t)L_5) < ((int32_t)3)))
		{
			goto IL_0004;
		}
	}
	{
		// }
		return;
	}
}
// System.Void UIManager::UpdateCompassionateSlider(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_UpdateCompassionateSlider_m1EAC1195B36B29BCA99A40352F55DFD1EFF9769C (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _compassionateSliders[GameManager.Instance.CompassionateStars].value = value;
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_0 = __this->____compassionateSliders_13;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_1 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = GameManager_get_CompassionateStars_mC10D44463CFC587C028B958A747A6A7BF8AFB799_inline(L_1, NULL);
		NullCheck(L_0);
		int32_t L_3 = L_2;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_4 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		int32_t L_5 = ___0_value;
		NullCheck(L_4);
		VirtualActionInvoker1< float >::Invoke(47 /* System.Void UnityEngine.UI.Slider::set_value(System.Single) */, L_4, ((float)L_5));
		// }
		return;
	}
}
// System.Void UIManager::UpdateDialogueBox(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_UpdateDialogueBox_mA80B91F523DE326AADA4C78971738159CCB0C0E6 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, String_t* ___0_newSentence, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponentInParent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m0EE7FD91A12A618B79D1B60D2ED73142D7CD65E9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (DialogueManager.Instance.IsQuery)
		DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* L_0 = ((DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_StaticFields*)il2cpp_codegen_static_fields_for(DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var))->___Instance_8;
		NullCheck(L_0);
		bool L_1;
		L_1 = DialogueManager_get_IsQuery_mCB820DB1AE6081487F94B1108B87FBACF7816DD8_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0057;
		}
	}
	{
		// _dialogueBox.font = _VCRFont;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_2 = __this->____dialogueBox_41;
		TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* L_3 = __this->____VCRFont_36;
		NullCheck(L_2);
		TMP_Text_set_font_mC55E4A8C1C09595031384B35F2C2FB2FC3479E83(L_2, L_3, NULL);
		// _dialogueBox.color = _incomingQueryColor;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_4 = __this->____dialogueBox_41;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_5 = __this->____incomingQueryColor_50;
		NullCheck(L_4);
		VirtualActionInvoker1< Color_tD001788D726C3A7F1379BEED0260B9591F440C1F >::Invoke(23 /* System.Void UnityEngine.UI.Graphic::set_color(UnityEngine.Color) */, L_4, L_5);
		// _dialogueBox.transform.GetComponentInParent<Image>().color = _incomingQueryColor;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_6 = __this->____dialogueBox_41;
		NullCheck(L_6);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_7;
		L_7 = TMP_Text_get_transform_m6BD41E08BFCFCE722DFCE4627626AD60CA99CCA8(L_6, NULL);
		NullCheck(L_7);
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_8;
		L_8 = Component_GetComponentInParent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m0EE7FD91A12A618B79D1B60D2ED73142D7CD65E9(L_7, Component_GetComponentInParent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m0EE7FD91A12A618B79D1B60D2ED73142D7CD65E9_RuntimeMethod_var);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_9 = __this->____incomingQueryColor_50;
		NullCheck(L_8);
		VirtualActionInvoker1< Color_tD001788D726C3A7F1379BEED0260B9591F440C1F >::Invoke(23 /* System.Void UnityEngine.UI.Graphic::set_color(UnityEngine.Color) */, L_8, L_9);
		// _runnerFace.enabled = false;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_10 = __this->____runnerFace_42;
		NullCheck(L_10);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_10, (bool)0, NULL);
		goto IL_00a0;
	}

IL_0057:
	{
		// _dialogueBox.font = _liberationFont;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_11 = __this->____dialogueBox_41;
		TMP_FontAsset_t923BF2F78D7C5AC36376E168A1193B7CB4855160* L_12 = __this->____liberationFont_35;
		NullCheck(L_11);
		TMP_Text_set_font_mC55E4A8C1C09595031384B35F2C2FB2FC3479E83(L_11, L_12, NULL);
		// _dialogueBox.color = _runnerDialogueColor;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_13 = __this->____dialogueBox_41;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_14 = __this->____runnerDialogueColor_49;
		NullCheck(L_13);
		VirtualActionInvoker1< Color_tD001788D726C3A7F1379BEED0260B9591F440C1F >::Invoke(23 /* System.Void UnityEngine.UI.Graphic::set_color(UnityEngine.Color) */, L_13, L_14);
		// _dialogueBox.transform.GetComponentInParent<Image>().color = _runnerDialogueColor;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_15 = __this->____dialogueBox_41;
		NullCheck(L_15);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_16;
		L_16 = TMP_Text_get_transform_m6BD41E08BFCFCE722DFCE4627626AD60CA99CCA8(L_15, NULL);
		NullCheck(L_16);
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_17;
		L_17 = Component_GetComponentInParent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m0EE7FD91A12A618B79D1B60D2ED73142D7CD65E9(L_16, Component_GetComponentInParent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m0EE7FD91A12A618B79D1B60D2ED73142D7CD65E9_RuntimeMethod_var);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_18 = __this->____runnerDialogueColor_49;
		NullCheck(L_17);
		VirtualActionInvoker1< Color_tD001788D726C3A7F1379BEED0260B9591F440C1F >::Invoke(23 /* System.Void UnityEngine.UI.Graphic::set_color(UnityEngine.Color) */, L_17, L_18);
		// _runnerFace.enabled = true;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_19 = __this->____runnerFace_42;
		NullCheck(L_19);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_19, (bool)1, NULL);
	}

IL_00a0:
	{
		// _isDialogueBoxOpen = true;
		__this->____isDialogueBoxOpen_40 = (bool)1;
		// _dialogueBox.transform.GetComponentInParent<Canvas>().enabled = true;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_20 = __this->____dialogueBox_41;
		NullCheck(L_20);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_21;
		L_21 = TMP_Text_get_transform_m6BD41E08BFCFCE722DFCE4627626AD60CA99CCA8(L_20, NULL);
		NullCheck(L_21);
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_22;
		L_22 = Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3(L_21, Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3_RuntimeMethod_var);
		NullCheck(L_22);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_22, (bool)1, NULL);
		// StopCoroutine(TypeSentence(_currentSentence));
		String_t* L_23 = __this->____currentSentence_51;
		RuntimeObject* L_24;
		L_24 = UIManager_TypeSentence_m6FAECFDF6029B0FA540597A1F1067990CE71A924(__this, L_23, NULL);
		MonoBehaviour_StopCoroutine_mF9E93B82091E804595BE13AA29F9AB7517F7E04A(__this, L_24, NULL);
		// StopCoroutine(FinishSentence());
		RuntimeObject* L_25;
		L_25 = UIManager_FinishSentence_mFBECD5FA7AD2A42506461EFB4AA0734856796177(__this, NULL);
		MonoBehaviour_StopCoroutine_mF9E93B82091E804595BE13AA29F9AB7517F7E04A(__this, L_25, NULL);
		// _currentSentence = newSentence;
		String_t* L_26 = ___0_newSentence;
		__this->____currentSentence_51 = L_26;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____currentSentence_51), (void*)L_26);
		// _typeOutSentence = true;
		__this->____typeOutSentence_39 = (bool)1;
		// StartCoroutine(TypeSentence(newSentence));
		String_t* L_27 = ___0_newSentence;
		RuntimeObject* L_28;
		L_28 = UIManager_TypeSentence_m6FAECFDF6029B0FA540597A1F1067990CE71A924(__this, L_27, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_29;
		L_29 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_28, NULL);
		// StartCoroutine(FinishSentence());
		RuntimeObject* L_30;
		L_30 = UIManager_FinishSentence_mFBECD5FA7AD2A42506461EFB4AA0734856796177(__this, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_31;
		L_31 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_30, NULL);
		// if (GameManager.NeedDialogueBoxHint) { StartCoroutine(HintDialogue()); }
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_32;
		L_32 = GameManager_get_NeedDialogueBoxHint_m2D72B960A1B248627A87A7CF0F5F5E8728C67C55_inline(NULL);
		if (!L_32)
		{
			goto IL_0118;
		}
	}
	{
		// if (GameManager.NeedDialogueBoxHint) { StartCoroutine(HintDialogue()); }
		RuntimeObject* L_33;
		L_33 = UIManager_HintDialogue_m0C7E9551F4E5A95C2F915FF40632B080F9ADEA25(__this, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_34;
		L_34 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_33, NULL);
	}

IL_0118:
	{
		// }
		return;
	}
}
// System.Collections.IEnumerator UIManager::TypeSentence(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_TypeSentence_m6FAECFDF6029B0FA540597A1F1067990CE71A924 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, String_t* ___0_sentence, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* L_0 = (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B*)il2cpp_codegen_object_new(U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CTypeSentenceU3Ed__57__ctor_m9895C4EF13ED39F948375519C39C50E51E171E5A(L_0, 0, NULL);
		U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* L_2 = L_1;
		String_t* L_3 = ___0_sentence;
		NullCheck(L_2);
		L_2->___sentence_3 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&L_2->___sentence_3), (void*)L_3);
		return L_2;
	}
}
// System.Collections.IEnumerator UIManager::FinishSentence()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_FinishSentence_mFBECD5FA7AD2A42506461EFB4AA0734856796177 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* L_0 = (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A*)il2cpp_codegen_object_new(U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CFinishSentenceU3Ed__58__ctor_m281085BF5E276CFBBC46C07932620E72779666CB(L_0, 0, NULL);
		U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		return L_1;
	}
}
// System.Void UIManager::AssignDialogueBox(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_AssignDialogueBox_mA02ACC08EF1AE90E9BF2FCDB6B88848362E6948F (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_runner, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisIRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_m4917A327E1DA277C56EA59748DD449F82FF7B190_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD1FD6003B70EF875A3B4801CB84EDB7013372DE2);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	{
		// IRunner r = runner.GetComponent<IRunner>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_runner;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = GameObject_GetComponent_TisIRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_m4917A327E1DA277C56EA59748DD449F82FF7B190(L_0, GameObject_GetComponent_TisIRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_m4917A327E1DA277C56EA59748DD449F82FF7B190_RuntimeMethod_var);
		V_0 = L_1;
		// if (r == null) { Debug.Log("Error! No runner found!"); return; }
		RuntimeObject* L_2 = V_0;
		if (L_2)
		{
			goto IL_0015;
		}
	}
	{
		// if (r == null) { Debug.Log("Error! No runner found!"); return; }
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(_stringLiteralD1FD6003B70EF875A3B4801CB84EDB7013372DE2, NULL);
		// if (r == null) { Debug.Log("Error! No runner found!"); return; }
		return;
	}

IL_0015:
	{
		// _dialogueBox = r.DialogueBox;
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_4;
		L_4 = InterfaceFuncInvoker0< TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* >::Invoke(6 /* TMPro.TextMeshProUGUI IRunner::get_DialogueBox() */, IRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_il2cpp_TypeInfo_var, L_3);
		__this->____dialogueBox_41 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____dialogueBox_41), (void*)L_4);
		// _runnerFace = r.RunnerFace;
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_6;
		L_6 = InterfaceFuncInvoker0< Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* >::Invoke(9 /* UnityEngine.UI.Image IRunner::get_RunnerFace() */, IRunner_t31B2D8BA06A5A72FAE7D4F6994991A9B4BA4288F_il2cpp_TypeInfo_var, L_5);
		__this->____runnerFace_42 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____runnerFace_42), (void*)L_6);
		// }
		return;
	}
}
// System.Void UIManager::HideDialogueBox()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_HideDialogueBox_mF51F524D06B33CD86E91434FCA908277DCADA981 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _dialogueBox.text = "";
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_0 = __this->____dialogueBox_41;
		NullCheck(L_0);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_0, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		// _dialogueBox.transform.GetChild(0).gameObject.SetActive(false);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_1 = __this->____dialogueBox_41;
		NullCheck(L_1);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = TMP_Text_get_transform_m6BD41E08BFCFCE722DFCE4627626AD60CA99CCA8(L_1, NULL);
		NullCheck(L_2);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_3;
		L_3 = Transform_GetChild_mE686DF0C7AAC1F7AEF356967B1C04D8B8E240EAF(L_2, 0, NULL);
		NullCheck(L_3);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4;
		L_4 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_3, NULL);
		NullCheck(L_4);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_4, (bool)0, NULL);
		// _dialogueBox.transform.GetComponentInParent<Canvas>().enabled = false;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_5 = __this->____dialogueBox_41;
		NullCheck(L_5);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_6;
		L_6 = TMP_Text_get_transform_m6BD41E08BFCFCE722DFCE4627626AD60CA99CCA8(L_5, NULL);
		NullCheck(L_6);
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_7;
		L_7 = Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3(L_6, Component_GetComponentInParent_TisCanvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26_m5FB554DD7C0F662DAB84C0F292B221CAE3F0A5B3_RuntimeMethod_var);
		NullCheck(L_7);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_7, (bool)0, NULL);
		// _isDialogueBoxOpen = false;
		__this->____isDialogueBoxOpen_40 = (bool)0;
		// }
		return;
	}
}
// System.Void UIManager::MainMenu()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_MainMenu_m266054608AA5ECFD724D14077C1800FC85CD5673 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponentInChildren_TisTextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957_m60A1B193FDBBFB3719065622DB5E0BB21CA4ABDC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral15E812F5755E8FB8F14234EC436436A5686DEAF4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral70DFB3A443EFAAF00DA135342763575F1A90FA54);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD3851214599FE0EFD555278BDD073CEEEE857BE5);
		s_Il2CppMethodInitialized = true;
	}
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* G_B2_0 = NULL;
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* G_B3_1 = NULL;
	{
		// _mainMenuCanvas.enabled = true;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_0 = __this->____mainMenuCanvas_16;
		NullCheck(L_0);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_0, (bool)1, NULL);
		// _loadingText.enabled = false;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_1 = __this->____loadingText_28;
		NullCheck(L_1);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_1, (bool)0, NULL);
		// _lifetimeStarsAmountMenu.text = "High Score: " + GameManager.HighScore.ToString();
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_2 = __this->____lifetimeStarsAmountMenu_7;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		String_t* L_3;
		L_3 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___HighScore_93), NULL);
		String_t* L_4;
		L_4 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral70DFB3A443EFAAF00DA135342763575F1A90FA54, L_3, NULL);
		NullCheck(L_2);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_2, L_4);
		// _storyModeButton.GetComponentInChildren<TextMeshProUGUI>().text = GameManager.GameUnderway ? "Continue Game" : "Start New Game";
		Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* L_5 = __this->____storyModeButton_23;
		NullCheck(L_5);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_6;
		L_6 = Component_GetComponentInChildren_TisTextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957_m60A1B193FDBBFB3719065622DB5E0BB21CA4ABDC(L_5, Component_GetComponentInChildren_TisTextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957_m60A1B193FDBBFB3719065622DB5E0BB21CA4ABDC_RuntimeMethod_var);
		bool L_7 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___GameUnderway_91;
		G_B1_0 = L_6;
		if (L_7)
		{
			G_B2_0 = L_6;
			goto IL_0050;
		}
	}
	{
		G_B3_0 = _stringLiteral15E812F5755E8FB8F14234EC436436A5686DEAF4;
		G_B3_1 = G_B1_0;
		goto IL_0055;
	}

IL_0050:
	{
		G_B3_0 = _stringLiteralD3851214599FE0EFD555278BDD073CEEEE857BE5;
		G_B3_1 = G_B2_0;
	}

IL_0055:
	{
		NullCheck(G_B3_1);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, G_B3_1, G_B3_0);
		// }
		return;
	}
}
// System.Void UIManager::BeginStage(GameState)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_BeginStage_m9765DBBC150EE6472BEFD406A5AE8DD387EB77AC (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_state, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCF5CB1E669F53D0126E0AB9DF27AE87BED33C783);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD99605E29810F93D7DAE4EFBB764C41AF4E80D32);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFD776C52B66598466031D7D1332E578D36A80810);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// if (state == GameState.Progressing)
		int32_t L_0 = ___0_state;
		if ((!(((uint32_t)L_0) == ((uint32_t)2))))
		{
			goto IL_008f;
		}
	}
	{
		// _topCanvas.enabled = true;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_1 = __this->____topCanvas_15;
		NullCheck(L_1);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_1, (bool)1, NULL);
		// _newHighScore.enabled = false;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_2 = __this->____newHighScore_8;
		NullCheck(L_2);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_2, (bool)0, NULL);
		// _activeSlider = _speedSliders[0];
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_3 = __this->____speedSliders_9;
		NullCheck(L_3);
		int32_t L_4 = 0;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_5 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		__this->____activeSlider_46 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____activeSlider_46), (void*)L_5);
		// _topTotalStarAmount.text = GameManager.AcquiredStars.ToString() + " ("
		// + GameManager.RequiredStars.ToString()
		// + " req.)";
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_6 = __this->____topTotalStarAmount_4;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline(NULL);
		V_0 = L_7;
		String_t* L_8;
		L_8 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		int32_t L_9;
		L_9 = GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline(NULL);
		V_0 = L_9;
		String_t* L_10;
		L_10 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		String_t* L_11;
		L_11 = String_Concat_m093934F71A9B351911EE46311674ED463B180006(L_8, _stringLiteralD99605E29810F93D7DAE4EFBB764C41AF4E80D32, L_10, _stringLiteralCF5CB1E669F53D0126E0AB9DF27AE87BED33C783, NULL);
		NullCheck(L_6);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_6, L_11);
		// _stageCurrentScore.text = "Current score: " + GameManager.CurrentScore.ToString();
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_12 = __this->____stageCurrentScore_5;
		int32_t L_13;
		L_13 = GameManager_get_CurrentScore_mCFD308B1545586CD81E7B5051BFE261008BD484C_inline(NULL);
		V_0 = L_13;
		String_t* L_14;
		L_14 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		String_t* L_15;
		L_15 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteralFD776C52B66598466031D7D1332E578D36A80810, L_14, NULL);
		NullCheck(L_12);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_12, L_15);
		// ResetSliders();
		UIManager_ResetSliders_m8CA4B0C1EAAE88785229FE0E77936A2CB6C9B03D(__this, NULL);
		// ResetStars();
		UIManager_ResetStars_m1E94D905F7430356C2D6B9F6F6FBB7ABBE6E14F4(__this, NULL);
	}

IL_008f:
	{
		// }
		return;
	}
}
// System.Void UIManager::EndStage()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_EndStage_mBB8377AFDBC3E9C61A70CF7CCCBD4737BD537270 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFD776C52B66598466031D7D1332E578D36A80810);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// _requiredStars.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->____requiredStars_10;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)0, NULL);
		// if (GameManager.GlobalDialogueCounter >= GameManager.MaxStages)
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_1 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___GlobalDialogueCounter_92;
		int32_t L_2;
		L_2 = GameManager_get_MaxStages_mB5F198316B9492B632EDB0669F1C594EF7DF3BE8(NULL);
		if ((((int32_t)L_1) < ((int32_t)L_2)))
		{
			goto IL_003e;
		}
	}
	{
		// _endStageButtons.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = __this->____endStageButtons_20;
		NullCheck(L_3);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_3, (bool)0, NULL);
		// if (GameManager.CurrentScore > GameManager.PreviousHighScore) // This is wrong!
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_4;
		L_4 = GameManager_get_CurrentScore_mCFD308B1545586CD81E7B5051BFE261008BD484C_inline(NULL);
		int32_t L_5 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___PreviousHighScore_94;
		if ((((int32_t)L_4) <= ((int32_t)L_5)))
		{
			goto IL_004a;
		}
	}
	{
		// _newHighScore.enabled = true;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_6 = __this->____newHighScore_8;
		NullCheck(L_6);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_6, (bool)1, NULL);
		goto IL_004a;
	}

IL_003e:
	{
		// _endStageButtons.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_7 = __this->____endStageButtons_20;
		NullCheck(L_7);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_7, (bool)1, NULL);
	}

IL_004a:
	{
		// _stageCanvas.enabled = true;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_8 = __this->____stageCanvas_14;
		NullCheck(L_8);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_8, (bool)1, NULL);
		// _stageCurrentScore.text = "Current score: " + (GameManager.CurrentScore - GameManager.AcquiredStars).ToString();
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_9 = __this->____stageCurrentScore_5;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_10;
		L_10 = GameManager_get_CurrentScore_mCFD308B1545586CD81E7B5051BFE261008BD484C_inline(NULL);
		int32_t L_11;
		L_11 = GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline(NULL);
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_10, L_11));
		String_t* L_12;
		L_12 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		String_t* L_13;
		L_13 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteralFD776C52B66598466031D7D1332E578D36A80810, L_12, NULL);
		NullCheck(L_9);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_9, L_13);
		// Assessment(GameManager.StageAnswerQuality);
		int32_t L_14;
		L_14 = GameManager_get_StageAnswerQuality_mCD07E8FED832C6E4AA0E6C875D02939D2CD92E16_inline(NULL);
		UIManager_Assessment_m4A7BC4F058D63345692A7C34597E0FC9C8048B34(__this, L_14, NULL);
		// StartCoroutine(BankStars(GameManager.AcquiredStars));
		int32_t L_15;
		L_15 = GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline(NULL);
		RuntimeObject* L_16;
		L_16 = UIManager_BankStars_m30DEC5BDD35083775406BB805945F715F5DF6A21(__this, L_15, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_17;
		L_17 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_16, NULL);
		// DialogueManager.Instance.NextAnswer(GameManager.CurrentStageDialogue);
		DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* L_18 = ((DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_StaticFields*)il2cpp_codegen_static_fields_for(DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var))->___Instance_8;
		StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* L_19;
		L_19 = GameManager_get_CurrentStageDialogue_m298FEF5012933892CF97212C2D056F0252EA3BA7_inline(NULL);
		NullCheck(L_18);
		DialogueManager_NextAnswer_mD45D15A36CDB58F3B18C915C2EC8F3B3D1790D86(L_18, L_19, NULL);
		// }
		return;
	}
}
// System.Collections.IEnumerator UIManager::BankStars(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_BankStars_m30DEC5BDD35083775406BB805945F715F5DF6A21 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_stars, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* L_0 = (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B*)il2cpp_codegen_object_new(U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CBankStarsU3Ed__64__ctor_m1B9DE110E86825630F79A735AA8107BBDC94B4F1(L_0, 0, NULL);
		U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* L_2 = L_1;
		int32_t L_3 = ___0_stars;
		NullCheck(L_2);
		L_2->___stars_3 = L_3;
		return L_2;
	}
}
// System.Void UIManager::Assessment(Answer)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_Assessment_m4A7BC4F058D63345692A7C34597E0FC9C8048B34 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_answer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral86279004B384FE920D53266948671806A3AF46C2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral91FA505304EDB1B3A1E99C1CE4AB8C2896809462);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD976CA0967453E34567684E0B79F556ED6E06573);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF2F1837B99915AFFC32DA9765ABF5788B4212459);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (answer == Answer.Poor)
		int32_t L_0 = ___0_answer;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		// _stageAssessment.text = "Incomplete answer, try again.";
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_1 = __this->____stageAssessment_6;
		NullCheck(L_1);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_1, _stringLiteral91FA505304EDB1B3A1E99C1CE4AB8C2896809462);
		return;
	}

IL_0014:
	{
		// else if (answer == Answer.Acceptable)
		int32_t L_2 = ___0_answer;
		if ((!(((uint32_t)L_2) == ((uint32_t)1))))
		{
			goto IL_0029;
		}
	}
	{
		// _stageAssessment.text = "Acceptable answer.";
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_3 = __this->____stageAssessment_6;
		NullCheck(L_3);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_3, _stringLiteral86279004B384FE920D53266948671806A3AF46C2);
		return;
	}

IL_0029:
	{
		// else if (answer == Answer.Excellent)
		int32_t L_4 = ___0_answer;
		if ((!(((uint32_t)L_4) == ((uint32_t)2))))
		{
			goto IL_003e;
		}
	}
	{
		// _stageAssessment.text = "Excellent answer!";
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_5 = __this->____stageAssessment_6;
		NullCheck(L_5);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_5, _stringLiteralD976CA0967453E34567684E0B79F556ED6E06573);
		return;
	}

IL_003e:
	{
		// else if (answer == Answer.Compassionate)
		int32_t L_6 = ___0_answer;
		if ((!(((uint32_t)L_6) == ((uint32_t)3))))
		{
			goto IL_0052;
		}
	}
	{
		// _stageAssessment.text = "Error: Answer outside AI limits.";
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_7 = __this->____stageAssessment_6;
		NullCheck(L_7);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_7, _stringLiteralF2F1837B99915AFFC32DA9765ABF5788B4212459);
	}

IL_0052:
	{
		// }
		return;
	}
}
// System.Void UIManager::GainStar(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_GainStar_mC2B8C93E19707CD2CC1DA97214AFE05B52B0836A (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, int32_t ___0_level, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCF5CB1E669F53D0126E0AB9DF27AE87BED33C783);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD99605E29810F93D7DAE4EFBB764C41AF4E80D32);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// _topTotalStarAmount.text = GameManager.AcquiredStars.ToString() + " ("
		//     + GameManager.RequiredStars.ToString()
		//     + " req.)";
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_0 = __this->____topTotalStarAmount_4;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline(NULL);
		V_0 = L_1;
		String_t* L_2;
		L_2 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		int32_t L_3;
		L_3 = GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline(NULL);
		V_0 = L_3;
		String_t* L_4;
		L_4 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		String_t* L_5;
		L_5 = String_Concat_m093934F71A9B351911EE46311674ED463B180006(L_2, _stringLiteralD99605E29810F93D7DAE4EFBB764C41AF4E80D32, L_4, _stringLiteralCF5CB1E669F53D0126E0AB9DF27AE87BED33C783, NULL);
		NullCheck(L_0);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_0, L_5);
		// _starParent.transform.GetChild(_newStarIndex % GameManager.RequiredStars)
		//     .GetChild(Mathf.Min(2 + _bonusStarIndex, 5)).gameObject.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6 = __this->____starParent_11;
		NullCheck(L_6);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_7;
		L_7 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_6, NULL);
		int32_t L_8 = __this->____newStarIndex_43;
		int32_t L_9;
		L_9 = GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline(NULL);
		NullCheck(L_7);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_10;
		L_10 = Transform_GetChild_mE686DF0C7AAC1F7AEF356967B1C04D8B8E240EAF(L_7, ((int32_t)(L_8%L_9)), NULL);
		int32_t L_11 = __this->____bonusStarIndex_44;
		int32_t L_12;
		L_12 = Mathf_Min_m888083F74FF5655778F0403BB5E9608BEFDEA8CB_inline(((int32_t)il2cpp_codegen_add(2, L_11)), 5, NULL);
		NullCheck(L_10);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_13;
		L_13 = Transform_GetChild_mE686DF0C7AAC1F7AEF356967B1C04D8B8E240EAF(L_10, L_12, NULL);
		NullCheck(L_13);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14;
		L_14 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_13, NULL);
		NullCheck(L_14);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_14, (bool)1, NULL);
		// _newStarIndex++;
		int32_t L_15 = __this->____newStarIndex_43;
		__this->____newStarIndex_43 = ((int32_t)il2cpp_codegen_add(L_15, 1));
		// if (level > _bonusStarIndex)
		int32_t L_16 = ___0_level;
		int32_t L_17 = __this->____bonusStarIndex_44;
		if ((((int32_t)L_16) <= ((int32_t)L_17)))
		{
			goto IL_00c0;
		}
	}
	{
		// _bonusStarIndex = level;
		int32_t L_18 = ___0_level;
		__this->____bonusStarIndex_44 = L_18;
		// if (_bonusStarIndex < _speedSliders.Length)
		int32_t L_19 = __this->____bonusStarIndex_44;
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_20 = __this->____speedSliders_9;
		NullCheck(L_20);
		if ((((int32_t)L_19) >= ((int32_t)((int32_t)(((RuntimeArray*)L_20)->max_length)))))
		{
			goto IL_00af;
		}
	}
	{
		// _activeSlider = _speedSliders[_bonusStarIndex];
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_21 = __this->____speedSliders_9;
		int32_t L_22 = __this->____bonusStarIndex_44;
		NullCheck(L_21);
		int32_t L_23 = L_22;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_24 = (L_21)->GetAt(static_cast<il2cpp_array_size_t>(L_23));
		__this->____activeSlider_46 = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____activeSlider_46), (void*)L_24);
	}

IL_00af:
	{
		// _activeSlider.gameObject.SetActive(true);
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_25 = __this->____activeSlider_46;
		NullCheck(L_25);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_26;
		L_26 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_25, NULL);
		NullCheck(L_26);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_26, (bool)1, NULL);
	}

IL_00c0:
	{
		// }
		return;
	}
}
// System.Void UIManager::ResetStars()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ResetStars_m1E94D905F7430356C2D6B9F6F6FBB7ABBE6E14F4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m07D362A07C19B36C2FD1B4DC79DD99903D4DA95D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m96F4B0BD0A5485C8E8CC57D961DF6F1FA256AF27_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m7236EBE1CFCB6533F96E030500D322B13D0CA5A4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Clear_m32D399BDD753B5BD6CE27560249096418F3F0867_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_mA843D26C63E5963415DFCA6E49DFA27AFD9C75E8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_2 = NULL;
	{
		// foreach (var star in _allStars)
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_0 = __this->____allStars_45;
		NullCheck(L_0);
		Enumerator_t88BD1282EF117E59AACFC9EC55B89F0B9EDACE60 L_1;
		L_1 = List_1_GetEnumerator_mA843D26C63E5963415DFCA6E49DFA27AFD9C75E8(L_0, List_1_GetEnumerator_mA843D26C63E5963415DFCA6E49DFA27AFD9C75E8_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002a:
			{// begin finally (depth: 1)
				Enumerator_Dispose_m07D362A07C19B36C2FD1B4DC79DD99903D4DA95D((&V_0), Enumerator_Dispose_m07D362A07C19B36C2FD1B4DC79DD99903D4DA95D_RuntimeMethod_var);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_001f_1;
			}

IL_000e_1:
			{
				// foreach (var star in _allStars)
				GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
				L_2 = Enumerator_get_Current_m7236EBE1CFCB6533F96E030500D322B13D0CA5A4_inline((&V_0), Enumerator_get_Current_m7236EBE1CFCB6533F96E030500D322B13D0CA5A4_RuntimeMethod_var);
				// Destroy(star.gameObject);
				NullCheck(L_2);
				GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3;
				L_3 = GameObject_get_gameObject_m0878015B8CF7F5D432B583C187725810D27B57DC(L_2, NULL);
				il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
				Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_3, NULL);
			}

IL_001f_1:
			{
				// foreach (var star in _allStars)
				bool L_4;
				L_4 = Enumerator_MoveNext_m96F4B0BD0A5485C8E8CC57D961DF6F1FA256AF27((&V_0), Enumerator_MoveNext_m96F4B0BD0A5485C8E8CC57D961DF6F1FA256AF27_RuntimeMethod_var);
				if (L_4)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_0038;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0038:
	{
		// _allStars.Clear();
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_5 = __this->____allStars_45;
		NullCheck(L_5);
		List_1_Clear_m32D399BDD753B5BD6CE27560249096418F3F0867_inline(L_5, List_1_Clear_m32D399BDD753B5BD6CE27560249096418F3F0867_RuntimeMethod_var);
		// _newStarIndex = 0;
		__this->____newStarIndex_43 = 0;
		// _bonusStarIndex = 0;
		__this->____bonusStarIndex_44 = 0;
		// for (int i = 0; i < GameManager.RequiredStars; i++)
		V_1 = 0;
		goto IL_007c;
	}

IL_0055:
	{
		// GameObject newStar = Instantiate(_starPrefab, _starParent.transform);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6 = __this->____starPrefab_18;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_7 = __this->____starParent_11;
		NullCheck(L_7);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_8;
		L_8 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_7, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_9;
		L_9 = Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811(L_6, L_8, Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811_RuntimeMethod_var);
		V_2 = L_9;
		// _allStars.Add(newStar);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_10 = __this->____allStars_45;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_11 = V_2;
		NullCheck(L_10);
		List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_inline(L_10, L_11, List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var);
		// for (int i = 0; i < GameManager.RequiredStars; i++)
		int32_t L_12 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
	}

IL_007c:
	{
		// for (int i = 0; i < GameManager.RequiredStars; i++)
		int32_t L_13 = V_1;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_14;
		L_14 = GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline(NULL);
		if ((((int32_t)L_13) < ((int32_t)L_14)))
		{
			goto IL_0055;
		}
	}
	{
		// ToggleCompassionateStars(false);
		UIManager_ToggleCompassionateStars_m29090082A7141ED6AB040EB3A7BFD064C9E02F67(__this, (bool)0, NULL);
		// ResetCompassionateStars();
		UIManager_ResetCompassionateStars_mEBF74575E2BED357C0D72B07631DC411AC5C16CC(__this, NULL);
		// }
		return;
	}
}
// System.Void UIManager::ResetSliders()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_ResetSliders_m8CA4B0C1EAAE88785229FE0E77936A2CB6C9B03D (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* V_0 = NULL;
	int32_t V_1 = 0;
	Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* V_2 = NULL;
	{
		// foreach (Slider slider in _speedSliders)
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_0 = __this->____speedSliders_9;
		V_0 = L_0;
		V_1 = 0;
		goto IL_0049;
	}

IL_000b:
	{
		// foreach (Slider slider in _speedSliders)
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_1 = V_0;
		int32_t L_2 = V_1;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_2 = L_4;
		// slider.maxValue = GameManager.RequiredStars * 100;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_5 = V_2;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_6;
		L_6 = GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline(NULL);
		NullCheck(L_5);
		Slider_set_maxValue_m43F3BF47C6D7063D80C578FD9B95AD88494203BE(L_5, ((float)((int32_t)il2cpp_codegen_multiply(L_6, ((int32_t)100)))), NULL);
		// slider.value = 0;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_7 = V_2;
		NullCheck(L_7);
		VirtualActionInvoker1< float >::Invoke(47 /* System.Void UnityEngine.UI.Slider::set_value(System.Single) */, L_7, (0.0f));
		// if (slider != _speedSliders[0]) { slider.gameObject.SetActive(false); }
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_8 = V_2;
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_9 = __this->____speedSliders_9;
		NullCheck(L_9);
		int32_t L_10 = 0;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_11 = (L_9)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_12;
		L_12 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_8, L_11, NULL);
		if (!L_12)
		{
			goto IL_0045;
		}
	}
	{
		// if (slider != _speedSliders[0]) { slider.gameObject.SetActive(false); }
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_13 = V_2;
		NullCheck(L_13);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14;
		L_14 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_13, NULL);
		NullCheck(L_14);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_14, (bool)0, NULL);
	}

IL_0045:
	{
		int32_t L_15 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_0049:
	{
		// foreach (Slider slider in _speedSliders)
		int32_t L_16 = V_1;
		SliderU5BU5D_t8C370FEDFB2E9506398D536519F63CC0DE050E55* L_17 = V_0;
		NullCheck(L_17);
		if ((((int32_t)L_16) < ((int32_t)((int32_t)(((RuntimeArray*)L_17)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		// }
		return;
	}
}
// System.Void UIManager::BlackScreenFadeOut()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_BlackScreenFadeOut_mA74743737254BACC2CC126AB239416EAA19FD143 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral508B359F5800B4F321A17F057E49D729C99EB0A9);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _blackScreenFadeOut.Play();
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0 = __this->____blackScreenFadeOut_32;
		NullCheck(L_0);
		bool L_1;
		L_1 = Animation_Play_m717560D2F561D9E12583AB3B435E6BC996448C3E(L_0, NULL);
		// GameManager.Instance.OpenMainMenu();
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_2 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_2);
		GameManager_OpenMainMenu_mD699596D765A018D44AF07793DF53DAACE6E18DE(L_2, NULL);
		// Invoke("DisableBlackScreenStart", 1.8f);
		MonoBehaviour_Invoke_mF724350C59362B0F1BFE26383209A274A29A63FB(__this, _stringLiteral508B359F5800B4F321A17F057E49D729C99EB0A9, (1.79999995f), NULL);
		// }
		return;
	}
}
// System.Void UIManager::BlackScreenFadeIn()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_BlackScreenFadeIn_mA8C7A7488676524CC74004C93A22A6C255B2DC5F (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _stageCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_0 = __this->____stageCanvas_14;
		NullCheck(L_0);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_0, (bool)0, NULL);
		// _blackScreenEnd.enabled = true;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_1 = __this->____blackScreenEnd_30;
		NullCheck(L_1);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_1, (bool)1, NULL);
		// _blackScreenEnd.color = new Color(0, 0, 0, 0);
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_2 = __this->____blackScreenEnd_30;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_3;
		memset((&L_3), 0, sizeof(L_3));
		Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline((&L_3), (0.0f), (0.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		NullCheck(L_2);
		VirtualActionInvoker1< Color_tD001788D726C3A7F1379BEED0260B9591F440C1F >::Invoke(23 /* System.Void UnityEngine.UI.Graphic::set_color(UnityEngine.Color) */, L_2, L_3);
		// _blackScreenFadeIn.Play();
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_4 = __this->____blackScreenFadeIn_33;
		NullCheck(L_4);
		bool L_5;
		L_5 = Animation_Play_m717560D2F561D9E12583AB3B435E6BC996448C3E(L_4, NULL);
		// StartCoroutine(EndCreditsRoll());
		RuntimeObject* L_6;
		L_6 = UIManager_EndCreditsRoll_m8C0F335EBD2B6222A711321E98D94584B1E1C1A4(__this, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_7;
		L_7 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_6, NULL);
		// GameManager.Instance.ResetDefaultSettings();
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_8 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_8);
		GameManager_ResetDefaultSettings_mF4FEE9BB6A9C74DC67FFADA42B0170BE36BA604E(L_8, NULL);
		// }
		return;
	}
}
// System.Collections.IEnumerator UIManager::MainMenuReset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_MainMenuReset_m072F87EE4F77D62EA13AA42B5D1E630B425A1EB4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* L_0 = (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B*)il2cpp_codegen_object_new(U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CMainMenuResetU3Ed__71__ctor_m851F0981FCD37DFC2AE2E617FE5DC67486FD8F2F(L_0, 0, NULL);
		U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		return L_1;
	}
}
// System.Collections.IEnumerator UIManager::EndCreditsRoll()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_EndCreditsRoll_m8C0F335EBD2B6222A711321E98D94584B1E1C1A4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* L_0 = (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1*)il2cpp_codegen_object_new(U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CEndCreditsRollU3Ed__72__ctor_m807C81428DCAB66E2B3F28CDDE747FFAC81961DF(L_0, 0, NULL);
		U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		return L_1;
	}
}
// System.Collections.IEnumerator UIManager::HintDialogue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* UIManager_HintDialogue_m0C7E9551F4E5A95C2F915FF40632B080F9ADEA25 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* L_0 = (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2*)il2cpp_codegen_object_new(U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CHintDialogueU3Ed__73__ctor_m94B102F2B01586664F5DC32D7986BF0494BF03C7(L_0, 0, NULL);
		U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		return L_1;
	}
}
// System.Void UIManager::DisableBlackScreenStart()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_DisableBlackScreenStart_m575AFC00DB3C7370630A1ADA861DE571F25586E9 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	{
		// _blackScreenStart.enabled = false;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_0 = __this->____blackScreenStart_29;
		NullCheck(L_0);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_0, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void UIManager::DeactivateBlackScreen()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_DeactivateBlackScreen_mD5096E7ECD998B0357C6D1A760B4165FC88F1EF5 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	{
		// _blackScreenEndDeactivated = true;
		__this->____blackScreenEndDeactivated_52 = (bool)1;
		// }
		return;
	}
}
// System.Void UIManager::OnContinueButtonClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnContinueButtonClick_mAA42C08726C56D19843960EA4F8C45D7A8BFD6F4 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* G_B3_0 = NULL;
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* G_B2_0 = NULL;
	{
		// _stageCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_0 = __this->____stageCanvas_14;
		NullCheck(L_0);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_0, (bool)0, NULL);
		// _stageAssessment.enabled = false;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_1 = __this->____stageAssessment_6;
		NullCheck(L_1);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_1, (bool)0, NULL);
		// if (GameManager.IsGameOver)
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = GameManager_get_IsGameOver_mF865E823B3B8F11883D33D15152D2680CE20AD33_inline(NULL);
		if (!L_2)
		{
			goto IL_003d;
		}
	}
	{
		// GameManager.OnNextTutorial?.Invoke(14);
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_3 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___OnNextTutorial_78;
		Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* L_4 = L_3;
		G_B2_0 = L_4;
		if (L_4)
		{
			G_B3_0 = L_4;
			goto IL_002a;
		}
	}
	{
		goto IL_0031;
	}

IL_002a:
	{
		NullCheck(G_B3_0);
		Action_1_Invoke_mAC3C34BA1905AB5B79E483CD9BB082B7D667F703_inline(G_B3_0, ((int32_t)14), NULL);
	}

IL_0031:
	{
		// GameManager.Instance.UpdateGameState(GameState.Transition);
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_5 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_5);
		GameManager_UpdateGameState_m74D3EC2581A497E87BF55A0C0EA6F17F1BB17D03(L_5, 1, NULL);
		// return;
		return;
	}

IL_003d:
	{
		// GameManager.Instance.SetupNextStage();
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_6 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_6);
		GameManager_SetupNextStage_m637E2D17484002DA036867261EAB2528367C64C1(L_6, NULL);
		// DialogueManager.Instance.EndDialogue();
		DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* L_7 = ((DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_StaticFields*)il2cpp_codegen_static_fields_for(DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var))->___Instance_8;
		NullCheck(L_7);
		DialogueManager_EndDialogue_m362F7B00007371C46591FE75AC073DA523731854(L_7, NULL);
		// DialogueManager.Instance.NextQuery(GameManager.CurrentStageDialogue);
		DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* L_8 = ((DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_StaticFields*)il2cpp_codegen_static_fields_for(DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241_il2cpp_TypeInfo_var))->___Instance_8;
		StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* L_9;
		L_9 = GameManager_get_CurrentStageDialogue_m298FEF5012933892CF97212C2D056F0252EA3BA7_inline(NULL);
		NullCheck(L_8);
		DialogueManager_NextQuery_m6BF8E6FE72B38B88DB8F95D628088E2C81DE9968(L_8, L_9, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnStoryModeButtonClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnStoryModeButtonClick_m9382FBF18F28991BD7A104DF02C466971030115E (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _mainMenuCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_0 = __this->____mainMenuCanvas_16;
		NullCheck(L_0);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_0, (bool)0, NULL);
		// GameManager.Instance.CloseMainMenu();
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_1 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_1);
		GameManager_CloseMainMenu_m4A4CC2BBCD9C4560DE1CC9638F8305FE6C4AC000(L_1, NULL);
		// OnContinueButtonClick();
		UIManager_OnContinueButtonClick_mAA42C08726C56D19843960EA4F8C45D7A8BFD6F4(__this, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnMenuSettingsClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnMenuSettingsClick_mDB9AF079B763EFB84E8D5E34E76A99C0340F4798 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	{
		// if (!_menuSettingsCanvas.enabled)
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_0 = __this->____menuSettingsCanvas_17;
		NullCheck(L_0);
		bool L_1;
		L_1 = Behaviour_get_enabled_mAAC9F15E9EBF552217A5AE2681589CC0BFA300C1(L_0, NULL);
		if (L_1)
		{
			goto IL_0026;
		}
	}
	{
		// _menuSettingsCanvas.enabled = true;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_2 = __this->____menuSettingsCanvas_17;
		NullCheck(L_2);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_2, (bool)1, NULL);
		// _mainMenuButtons.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = __this->____mainMenuButtons_19;
		NullCheck(L_3);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_3, (bool)0, NULL);
		return;
	}

IL_0026:
	{
		// _menuSettingsCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_4 = __this->____menuSettingsCanvas_17;
		NullCheck(L_4);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_4, (bool)0, NULL);
		// _mainMenuButtons.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = __this->____mainMenuButtons_19;
		NullCheck(L_5);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_5, (bool)1, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnStageSettingsClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnStageSettingsClick_mDA9C1B092352182033E49BAE92C66D16F8850B28 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!_menuSettingsCanvas.enabled)
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_0 = __this->____menuSettingsCanvas_17;
		NullCheck(L_0);
		bool L_1;
		L_1 = Behaviour_get_enabled_mAAC9F15E9EBF552217A5AE2681589CC0BFA300C1(L_0, NULL);
		if (L_1)
		{
			goto IL_0042;
		}
	}
	{
		// GameManager.IsStageMenuOpen = true;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsStageMenuOpen_m8A712BA74947AD95FA3444508E8533F8644F3CAD_inline((bool)1, NULL);
		// _menuSettingsCanvas.enabled = true;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_2 = __this->____menuSettingsCanvas_17;
		NullCheck(L_2);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_2, (bool)1, NULL);
		// _resetButton.gameObject.SetActive(false);
		Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* L_3 = __this->____resetButton_27;
		NullCheck(L_3);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4;
		L_4 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_3, NULL);
		NullCheck(L_4);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_4, (bool)0, NULL);
		// _quitToMenuButton.gameObject.SetActive(true);
		Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* L_5 = __this->____quitToMenuButton_26;
		NullCheck(L_5);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6;
		L_6 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_5, NULL);
		NullCheck(L_6);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_6, (bool)1, NULL);
		return;
	}

IL_0042:
	{
		// GameManager.IsStageMenuOpen = false;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsStageMenuOpen_m8A712BA74947AD95FA3444508E8533F8644F3CAD_inline((bool)0, NULL);
		// _menuSettingsCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_7 = __this->____menuSettingsCanvas_17;
		NullCheck(L_7);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_7, (bool)0, NULL);
		// _resetButton.gameObject.SetActive(true);
		Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* L_8 = __this->____resetButton_27;
		NullCheck(L_8);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_9;
		L_9 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_8, NULL);
		NullCheck(L_9);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_9, (bool)1, NULL);
		// _quitToMenuButton.gameObject.SetActive(false);
		Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* L_10 = __this->____quitToMenuButton_26;
		NullCheck(L_10);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_11;
		L_11 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_10, NULL);
		NullCheck(L_11);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_11, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnBackButtonClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnBackButtonClick_m9F634722D55A33EAE13BEA0ECAD1303F3A584AE6 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _mainMenuButtons.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->____mainMenuButtons_19;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)1, NULL);
		// _resetButton.gameObject.SetActive(true);
		Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* L_1 = __this->____resetButton_27;
		NullCheck(L_1);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_1, NULL);
		NullCheck(L_2);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_2, (bool)1, NULL);
		// _menuSettingsCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_3 = __this->____menuSettingsCanvas_17;
		NullCheck(L_3);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_3, (bool)0, NULL);
		// _quitToMenuButton.gameObject.SetActive(false);
		Button_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098* L_4 = __this->____quitToMenuButton_26;
		NullCheck(L_4);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5;
		L_5 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_4, NULL);
		NullCheck(L_5);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_5, (bool)0, NULL);
		// GameManager.IsStageMenuOpen = false;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsStageMenuOpen_m8A712BA74947AD95FA3444508E8533F8644F3CAD_inline((bool)0, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnResetGame()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnResetGame_mAE99952CEDB1915CBD16723A35836AB3708F573A (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	{
		// _backPage.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->____backPage_22;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)1, NULL);
		// _mainPage.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = __this->____mainPage_21;
		NullCheck(L_1);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_1, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnYesToResetClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnYesToResetClick_m9454876FBB5A83ADB475367EE89596BA0137C6BD (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SaveData_tCAF56A3D01300E493D55A0B105DAA8D6F2015C1C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// SaveData.ClearAllSettings();
		il2cpp_codegen_runtime_class_init_inline(SaveData_tCAF56A3D01300E493D55A0B105DAA8D6F2015C1C_il2cpp_TypeInfo_var);
		SaveData_ClearAllSettings_m52625A0058652FBE5321F0E0BC7D06DE3269919C(NULL);
		// GameManager.Instance.LoadDefaultSettings();
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_0);
		GameManager_LoadDefaultSettings_mD2A1CA3417352CF5B3789B64A7AFD4B5BC22825B(L_0, NULL);
		// GameManager.HighScore = 0;
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___HighScore_93 = 0;
		// OnQuitToMenu();
		UIManager_OnQuitToMenu_mF966FF59A27A00115B39EE76A8A917829E43B3B5(__this, NULL);
		// }
		return;
	}
}
// System.Void UIManager::OnQuitToMenu()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_OnQuitToMenu_mF966FF59A27A00115B39EE76A8A917829E43B3B5 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _menuSettingsCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_0 = __this->____menuSettingsCanvas_17;
		NullCheck(L_0);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_0, (bool)0, NULL);
		// _topCanvas.enabled = false;
		Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* L_1 = __this->____topCanvas_15;
		NullCheck(L_1);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_1, (bool)0, NULL);
		// _blackScreenStart.color = Color.black;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_2 = __this->____blackScreenStart_29;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_3;
		L_3 = Color_get_black_mB50217951591A045844C61E7FF31EEE3FEF16737_inline(NULL);
		NullCheck(L_2);
		VirtualActionInvoker1< Color_tD001788D726C3A7F1379BEED0260B9591F440C1F >::Invoke(23 /* System.Void UnityEngine.UI.Graphic::set_color(UnityEngine.Color) */, L_2, L_3);
		// _blackScreenStart.enabled = true;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_4 = __this->____blackScreenStart_29;
		NullCheck(L_4);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_4, (bool)1, NULL);
		// GameManager.IsStageMenuOpen = false;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_IsStageMenuOpen_m8A712BA74947AD95FA3444508E8533F8644F3CAD_inline((bool)0, NULL);
		// GameManager.Instance.QuitToMenu();
		GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* L_5 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->___Instance_82;
		NullCheck(L_5);
		GameManager_QuitToMenu_m8BD0046A2E4FE4598B5558DA32F8258FFC67E8F6(L_5, NULL);
		// _loadingText.enabled = true;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_6 = __this->____loadingText_28;
		NullCheck(L_6);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_6, (bool)1, NULL);
		// StartCoroutine(MainMenuReset());
		RuntimeObject* L_7;
		L_7 = UIManager_MainMenuReset_m072F87EE4F77D62EA13AA42B5D1E630B425A1EB4(__this, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_8;
		L_8 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_7, NULL);
		// }
		return;
	}
}
// System.Void UIManager::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager__ctor_m1BA4EA1394AD31D64239F1D1E4DF554FD6B329D3 (UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private WaitForSecondsRealtime _sentenceDelay = new WaitForSecondsRealtime(1f);
		WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* L_0 = (WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01*)il2cpp_codegen_object_new(WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		WaitForSecondsRealtime__ctor_mBFC1E4F0E042D5EC6E7EEB211A2FE5193A8F6D6F(L_0, (1.0f), NULL);
		__this->____sentenceDelay_37 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____sentenceDelay_37), (void*)L_0);
		// private WaitForSecondsRealtime _starGainDelay = new WaitForSecondsRealtime(0.35f);
		WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* L_1 = (WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01*)il2cpp_codegen_object_new(WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		WaitForSecondsRealtime__ctor_mBFC1E4F0E042D5EC6E7EEB211A2FE5193A8F6D6F(L_1, (0.349999994f), NULL);
		__this->____starGainDelay_38 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____starGainDelay_38), (void*)L_1);
		// private bool _typeOutSentence = true;
		__this->____typeOutSentence_39 = (bool)1;
		// private List<GameObject> _allStars = new List<GameObject>();
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_2 = (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*)il2cpp_codegen_object_new(List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC(L_2, List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var);
		__this->____allStars_45 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____allStars_45), (void*)L_2);
		// private WaitForSecondsRealtime _hintDelay = new WaitForSecondsRealtime(3f);
		WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* L_3 = (WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01*)il2cpp_codegen_object_new(WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		WaitForSecondsRealtime__ctor_mBFC1E4F0E042D5EC6E7EEB211A2FE5193A8F6D6F(L_3, (3.0f), NULL);
		__this->____hintDelay_47 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____hintDelay_47), (void*)L_3);
		// private WaitForSeconds _menuResetDelay = new WaitForSeconds(5f);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_4 = (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3*)il2cpp_codegen_object_new(WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC(L_4, (5.0f), NULL);
		__this->____menuResetDelay_48 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____menuResetDelay_48), (void*)L_4);
		// private Color _runnerDialogueColor = new Color(0.478f, 1f, 1f, 1f);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_5;
		memset((&L_5), 0, sizeof(L_5));
		Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline((&L_5), (0.477999985f), (1.0f), (1.0f), (1.0f), /*hidden argument*/NULL);
		__this->____runnerDialogueColor_49 = L_5;
		// private Color _incomingQueryColor = new Color(0f, 0.764f, 0f, 1f);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_6;
		memset((&L_6), 0, sizeof(L_6));
		Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline((&L_6), (0.0f), (0.763999999f), (0.0f), (1.0f), /*hidden argument*/NULL);
		__this->____incomingQueryColor_50 = L_6;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager/<TypeSentence>d__57::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTypeSentenceU3Ed__57__ctor_m9895C4EF13ED39F948375519C39C50E51E171E5A (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void UIManager/<TypeSentence>d__57::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTypeSentenceU3Ed__57_System_IDisposable_Dispose_m889B4C6F5892842C4DED500B52302AE269FA9471 (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UIManager/<TypeSentence>d__57::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CTypeSentenceU3Ed__57_MoveNext_mCFFB1F93E25B6DED53A88FF8E65E2644C51AABB5 (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* V_1 = NULL;
	Il2CppChar V_2 = 0x0;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_1 = __this->___U3CU3E4__this_2;
		V_1 = L_1;
		int32_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_008b;
		}
	}
	{
		return (bool)0;
	}

IL_0017:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// _dialogueBox.text = "";
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_4 = V_1;
		NullCheck(L_4);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_5 = L_4->____dialogueBox_41;
		NullCheck(L_5);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_5, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		// foreach (char letter in sentence.ToCharArray())
		String_t* L_6 = __this->___sentence_3;
		NullCheck(L_6);
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_7;
		L_7 = String_ToCharArray_m0699A92AA3E744229EF29CB9D943C47DF4FE5B46(L_6, NULL);
		__this->___U3CU3E7__wrap1_4 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E7__wrap1_4), (void*)L_7);
		__this->___U3CU3E7__wrap2_5 = 0;
		goto IL_00a0;
	}

IL_0048:
	{
		// foreach (char letter in sentence.ToCharArray())
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_8 = __this->___U3CU3E7__wrap1_4;
		int32_t L_9 = __this->___U3CU3E7__wrap2_5;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		uint16_t L_11 = (uint16_t)(L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_2 = L_11;
		// if (_typeOutSentence)
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_12 = V_1;
		NullCheck(L_12);
		bool L_13 = L_12->____typeOutSentence_39;
		if (!L_13)
		{
			goto IL_00b0;
		}
	}
	{
		// _dialogueBox.text += letter;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_14 = V_1;
		NullCheck(L_14);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_15 = L_14->____dialogueBox_41;
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_16 = L_15;
		NullCheck(L_16);
		String_t* L_17;
		L_17 = VirtualFuncInvoker0< String_t* >::Invoke(65 /* System.String TMPro.TMP_Text::get_text() */, L_16);
		String_t* L_18;
		L_18 = Char_ToString_m2A308731F9577C06AF3C0901234E2EAC8327410C((&V_2), NULL);
		String_t* L_19;
		L_19 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_17, L_18, NULL);
		NullCheck(L_16);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_16, L_19);
		// yield return null;
		__this->___U3CU3E2__current_1 = NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)NULL);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_008b:
	{
		__this->___U3CU3E1__state_0 = (-1);
		int32_t L_20 = __this->___U3CU3E7__wrap2_5;
		__this->___U3CU3E7__wrap2_5 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_00a0:
	{
		// foreach (char letter in sentence.ToCharArray())
		int32_t L_21 = __this->___U3CU3E7__wrap2_5;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_22 = __this->___U3CU3E7__wrap1_4;
		NullCheck(L_22);
		if ((((int32_t)L_21) < ((int32_t)((int32_t)(((RuntimeArray*)L_22)->max_length)))))
		{
			goto IL_0048;
		}
	}

IL_00b0:
	{
		__this->___U3CU3E7__wrap1_4 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E7__wrap1_4), (void*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)NULL);
		// }
		return (bool)0;
	}
}
// System.Object UIManager/<TypeSentence>d__57::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CTypeSentenceU3Ed__57_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m3AB2D6BE058FCB250EB880A6EE73501909188A74 (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UIManager/<TypeSentence>d__57::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTypeSentenceU3Ed__57_System_Collections_IEnumerator_Reset_m23A5F712ECE79A24516A88B21EE5FF5D37AD0608 (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CTypeSentenceU3Ed__57_System_Collections_IEnumerator_Reset_m23A5F712ECE79A24516A88B21EE5FF5D37AD0608_RuntimeMethod_var)));
	}
}
// System.Object UIManager/<TypeSentence>d__57::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CTypeSentenceU3Ed__57_System_Collections_IEnumerator_get_Current_m4A7812A428FBF68ACB932E0035D8A15C5E1B486A (U3CTypeSentenceU3Ed__57_tFF9E5FD6F1CC9CE2BFEBA7731604D5452D61752B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager/<FinishSentence>d__58::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CFinishSentenceU3Ed__58__ctor_m281085BF5E276CFBBC46C07932620E72779666CB (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void UIManager/<FinishSentence>d__58::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CFinishSentenceU3Ed__58_System_IDisposable_Dispose_m5F09C87FEB6B5BF1BF2BE4E8ADCAAAF129C6A5A1 (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UIManager/<FinishSentence>d__58::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CFinishSentenceU3Ed__58_MoveNext_m20D46E512D1C118B1C5C908AE69047EC74DC98E1 (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* V_1 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_1 = __this->___U3CU3E4__this_2;
		V_1 = L_1;
		int32_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0033;
		}
	}
	{
		return (bool)0;
	}

IL_0017:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// yield return _sentenceDelay;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_4 = V_1;
		NullCheck(L_4);
		WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* L_5 = L_4->____sentenceDelay_37;
		__this->___U3CU3E2__current_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_5);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0033:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// _typeOutSentence = false;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_6 = V_1;
		NullCheck(L_6);
		L_6->____typeOutSentence_39 = (bool)0;
		// _dialogueBox.text = _currentSentence;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_7 = V_1;
		NullCheck(L_7);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_8 = L_7->____dialogueBox_41;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_9 = V_1;
		NullCheck(L_9);
		String_t* L_10 = L_9->____currentSentence_51;
		NullCheck(L_8);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_8, L_10);
		// }
		return (bool)0;
	}
}
// System.Object UIManager/<FinishSentence>d__58::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CFinishSentenceU3Ed__58_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_mC44075FCAD975B51AC34D4C9429B37AF0650EFBC (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UIManager/<FinishSentence>d__58::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CFinishSentenceU3Ed__58_System_Collections_IEnumerator_Reset_m9BFFBDFA9138A35F75751D01AB6FEF52C32BBEC2 (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CFinishSentenceU3Ed__58_System_Collections_IEnumerator_Reset_m9BFFBDFA9138A35F75751D01AB6FEF52C32BBEC2_RuntimeMethod_var)));
	}
}
// System.Object UIManager/<FinishSentence>d__58::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CFinishSentenceU3Ed__58_System_Collections_IEnumerator_get_Current_m0650F496EC64C5894BC722EFADFDFAEADA1C7EAE (U3CFinishSentenceU3Ed__58_t01F7498144F232ADFCE1ACA75557FC6BFB0D706A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager/<BankStars>d__64::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CBankStarsU3Ed__64__ctor_m1B9DE110E86825630F79A735AA8107BBDC94B4F1 (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void UIManager/<BankStars>d__64::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CBankStarsU3Ed__64_System_IDisposable_Dispose_m95DE1FDD492E4A2DA9CF9F39F997A11FBC7724DF (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UIManager/<BankStars>d__64::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CBankStarsU3Ed__64_MoveNext_mFE1AE9C2BD675314DC3CB513313FA163C90D7F1F (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCF5CB1E669F53D0126E0AB9DF27AE87BED33C783);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD99605E29810F93D7DAE4EFBB764C41AF4E80D32);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFD776C52B66598466031D7D1332E578D36A80810);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* V_1 = NULL;
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_1 = __this->___U3CU3E4__this_2;
		V_1 = L_1;
		int32_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_003f;
		}
	}
	{
		return (bool)0;
	}

IL_0017:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// for (int i = 1; i <= stars; i++)
		__this->___U3CiU3E5__2_4 = 1;
		goto IL_00cf;
	}

IL_002a:
	{
		// yield return _starGainDelay;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_4 = V_1;
		NullCheck(L_4);
		WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* L_5 = L_4->____starGainDelay_38;
		__this->___U3CU3E2__current_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_5);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_003f:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// _stageCurrentScore.text = "Current score: " + (GameManager.CurrentScore - GameManager.AcquiredStars + i).ToString();
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_6 = V_1;
		NullCheck(L_6);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_7 = L_6->____stageCurrentScore_5;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_8;
		L_8 = GameManager_get_CurrentScore_mCFD308B1545586CD81E7B5051BFE261008BD484C_inline(NULL);
		int32_t L_9;
		L_9 = GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline(NULL);
		int32_t L_10 = __this->___U3CiU3E5__2_4;
		V_2 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_8, L_9)), L_10));
		String_t* L_11;
		L_11 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_2), NULL);
		String_t* L_12;
		L_12 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteralFD776C52B66598466031D7D1332E578D36A80810, L_11, NULL);
		NullCheck(L_7);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_7, L_12);
		// _topTotalStarAmount.text = (GameManager.AcquiredStars - i).ToString()
		//     + " ("
		//     + GameManager.RequiredStars.ToString()
		//     + " req.)";
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_13 = V_1;
		NullCheck(L_13);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_14 = L_13->____topTotalStarAmount_4;
		int32_t L_15;
		L_15 = GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline(NULL);
		int32_t L_16 = __this->___U3CiU3E5__2_4;
		V_2 = ((int32_t)il2cpp_codegen_subtract(L_15, L_16));
		String_t* L_17;
		L_17 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_2), NULL);
		int32_t L_18;
		L_18 = GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline(NULL);
		V_2 = L_18;
		String_t* L_19;
		L_19 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_2), NULL);
		String_t* L_20;
		L_20 = String_Concat_m093934F71A9B351911EE46311674ED463B180006(L_17, _stringLiteralD99605E29810F93D7DAE4EFBB764C41AF4E80D32, L_19, _stringLiteralCF5CB1E669F53D0126E0AB9DF27AE87BED33C783, NULL);
		NullCheck(L_14);
		VirtualActionInvoker1< String_t* >::Invoke(66 /* System.Void TMPro.TMP_Text::set_text(System.String) */, L_14, L_20);
		// AudioManager.Instance.UIStar.Play();
		AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613* L_21 = ((AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_StaticFields*)il2cpp_codegen_static_fields_for(AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var))->___Instance_26;
		NullCheck(L_21);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_22 = L_21->___UIStar_20;
		NullCheck(L_22);
		AudioSource_Play_m95DF07111C61D0E0F00257A00384D31531D590C3(L_22, NULL);
		// for (int i = 1; i <= stars; i++)
		int32_t L_23 = __this->___U3CiU3E5__2_4;
		V_2 = L_23;
		int32_t L_24 = V_2;
		__this->___U3CiU3E5__2_4 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_00cf:
	{
		// for (int i = 1; i <= stars; i++)
		int32_t L_25 = __this->___U3CiU3E5__2_4;
		int32_t L_26 = __this->___stars_3;
		if ((((int32_t)L_25) <= ((int32_t)L_26)))
		{
			goto IL_002a;
		}
	}
	{
		// _stageAssessment.enabled = true;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_27 = V_1;
		NullCheck(L_27);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_28 = L_27->____stageAssessment_6;
		NullCheck(L_28);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_28, (bool)1, NULL);
		// AudioManager.Instance.UILevelDone.Play(); // Change this depending on answer quality
		AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613* L_29 = ((AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_StaticFields*)il2cpp_codegen_static_fields_for(AudioManager_t6D07140015098E8E7109BA8FD297F4537104D613_il2cpp_TypeInfo_var))->___Instance_26;
		NullCheck(L_29);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_30 = L_29->___UILevelDone_21;
		NullCheck(L_30);
		AudioSource_Play_m95DF07111C61D0E0F00257A00384D31531D590C3(L_30, NULL);
		// }
		return (bool)0;
	}
}
// System.Object UIManager/<BankStars>d__64::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CBankStarsU3Ed__64_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_mF2ABA54A58E92D9B3B4CE0341A81933B1BBF032E (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UIManager/<BankStars>d__64::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CBankStarsU3Ed__64_System_Collections_IEnumerator_Reset_mC6DDFFC1B8C066EAF53F9B3E8D29BFC724241213 (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CBankStarsU3Ed__64_System_Collections_IEnumerator_Reset_mC6DDFFC1B8C066EAF53F9B3E8D29BFC724241213_RuntimeMethod_var)));
	}
}
// System.Object UIManager/<BankStars>d__64::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CBankStarsU3Ed__64_System_Collections_IEnumerator_get_Current_m4169D90E4C0BD758BED07E041D2D2582A72F949D (U3CBankStarsU3Ed__64_tEB210D0577C162CEB6C4DBC28820FDF5E2AA225B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager/<MainMenuReset>d__71::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CMainMenuResetU3Ed__71__ctor_m851F0981FCD37DFC2AE2E617FE5DC67486FD8F2F (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void UIManager/<MainMenuReset>d__71::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CMainMenuResetU3Ed__71_System_IDisposable_Dispose_mC47F82A1AAFF29BB73A37F803865F05EE1556389 (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UIManager/<MainMenuReset>d__71::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CMainMenuResetU3Ed__71_MoveNext_m818F3A5621498AFB63487EA7E70820CA45C8B2B6 (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral508B359F5800B4F321A17F057E49D729C99EB0A9);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* V_1 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_1 = __this->___U3CU3E4__this_2;
		V_1 = L_1;
		int32_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0033;
		}
	}
	{
		return (bool)0;
	}

IL_0017:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// yield return _menuResetDelay;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_4 = V_1;
		NullCheck(L_4);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_5 = L_4->____menuResetDelay_48;
		__this->___U3CU3E2__current_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_5);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0033:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// _blackScreenFadeOut.Play();
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_6 = V_1;
		NullCheck(L_6);
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_7 = L_6->____blackScreenFadeOut_32;
		NullCheck(L_7);
		bool L_8;
		L_8 = Animation_Play_m717560D2F561D9E12583AB3B435E6BC996448C3E(L_7, NULL);
		// Invoke("DisableBlackScreenStart", 1.8f);
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_9 = V_1;
		NullCheck(L_9);
		MonoBehaviour_Invoke_mF724350C59362B0F1BFE26383209A274A29A63FB(L_9, _stringLiteral508B359F5800B4F321A17F057E49D729C99EB0A9, (1.79999995f), NULL);
		// _loadingText.enabled = false;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_10 = V_1;
		NullCheck(L_10);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_11 = L_10->____loadingText_28;
		NullCheck(L_11);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_11, (bool)0, NULL);
		// }
		return (bool)0;
	}
}
// System.Object UIManager/<MainMenuReset>d__71::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CMainMenuResetU3Ed__71_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_mD06DBA7F68366BE544C0D8756A6D2C9245385DD4 (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UIManager/<MainMenuReset>d__71::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CMainMenuResetU3Ed__71_System_Collections_IEnumerator_Reset_m9240752811EDAF53425A69F3F82AA10BCFDCD4A4 (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CMainMenuResetU3Ed__71_System_Collections_IEnumerator_Reset_m9240752811EDAF53425A69F3F82AA10BCFDCD4A4_RuntimeMethod_var)));
	}
}
// System.Object UIManager/<MainMenuReset>d__71::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CMainMenuResetU3Ed__71_System_Collections_IEnumerator_get_Current_m83D0108F3A7085B7C5259D6A1C8D6ED9790883D2 (U3CMainMenuResetU3Ed__71_t574843F42A96096A5C9ACD865BCAA1500D64EA7B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager/<EndCreditsRoll>d__72::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CEndCreditsRollU3Ed__72__ctor_m807C81428DCAB66E2B3F28CDDE747FFAC81961DF (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void UIManager/<EndCreditsRoll>d__72::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CEndCreditsRollU3Ed__72_System_IDisposable_Dispose_mE309F00946D45AFB4A6013A79B2897D39F3618D2 (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UIManager/<EndCreditsRoll>d__72::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CEndCreditsRollU3Ed__72_MoveNext_m74474FD5B5AC7B658685A67EFFF2F67CC87F9604 (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC84BECFBE67D1CE6878DF6A48AC0DE515B4A85B1);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* V_1 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_1 = __this->___U3CU3E4__this_2;
		V_1 = L_1;
		int32_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_005f;
		}
	}
	{
		return (bool)0;
	}

IL_0017:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// _endCreditsObj.SetActive(true);
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_4 = V_1;
		NullCheck(L_4);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = L_4->____endCreditsObj_31;
		NullCheck(L_5);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_5, (bool)1, NULL);
		// _endCreditsAnimation.Play();
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_6 = V_1;
		NullCheck(L_6);
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_7 = L_6->____endCreditsAnimation_34;
		NullCheck(L_7);
		bool L_8;
		L_8 = Animation_Play_m717560D2F561D9E12583AB3B435E6BC996448C3E(L_7, NULL);
		// yield return new WaitForSeconds(_endCreditsAnimation.GetClip("CreditScroll").length);
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_9 = V_1;
		NullCheck(L_9);
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_10 = L_9->____endCreditsAnimation_34;
		NullCheck(L_10);
		AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712* L_11;
		L_11 = Animation_GetClip_m566FFEC9EA0EA79DB1BAC0B79F37CD6A3A85C296(L_10, _stringLiteralC84BECFBE67D1CE6878DF6A48AC0DE515B4A85B1, NULL);
		NullCheck(L_11);
		float L_12;
		L_12 = AnimationClip_get_length_mAD91A1C134662285F26886489AC2D8E0EC79AF41(L_11, NULL);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_13 = (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3*)il2cpp_codegen_object_new(WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		NullCheck(L_13);
		WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC(L_13, L_12, NULL);
		__this->___U3CU3E2__current_1 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_13);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_005f:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// if (!_blackScreenEndDeactivated)
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_14 = V_1;
		NullCheck(L_14);
		bool L_15 = L_14->____blackScreenEndDeactivated_52;
		if (L_15)
		{
			goto IL_0093;
		}
	}
	{
		// _blackScreenEndDeactivated = true;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_16 = V_1;
		NullCheck(L_16);
		L_16->____blackScreenEndDeactivated_52 = (bool)1;
		// _endCreditsObj.SetActive(false);
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_17 = V_1;
		NullCheck(L_17);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_18 = L_17->____endCreditsObj_31;
		NullCheck(L_18);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_18, (bool)0, NULL);
		// _blackScreenEnd.enabled = false;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_19 = V_1;
		NullCheck(L_19);
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_20 = L_19->____blackScreenEnd_30;
		NullCheck(L_20);
		Behaviour_set_enabled_mF1DCFE60EB09E0529FE9476CA804A3AA2D72B16A(L_20, (bool)0, NULL);
		// OnQuitToMenu();
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_21 = V_1;
		NullCheck(L_21);
		UIManager_OnQuitToMenu_mF966FF59A27A00115B39EE76A8A917829E43B3B5(L_21, NULL);
	}

IL_0093:
	{
		// }
		return (bool)0;
	}
}
// System.Object UIManager/<EndCreditsRoll>d__72::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CEndCreditsRollU3Ed__72_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m763221011200D59B7A7E5520F502EA3D07BAA7A6 (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UIManager/<EndCreditsRoll>d__72::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CEndCreditsRollU3Ed__72_System_Collections_IEnumerator_Reset_m7D4782D4CA20065755C789F61F741C9F363F13B5 (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CEndCreditsRollU3Ed__72_System_Collections_IEnumerator_Reset_m7D4782D4CA20065755C789F61F741C9F363F13B5_RuntimeMethod_var)));
	}
}
// System.Object UIManager/<EndCreditsRoll>d__72::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CEndCreditsRollU3Ed__72_System_Collections_IEnumerator_get_Current_mD8E1ABD995ACEAB7C95E171432367695D373B86F (U3CEndCreditsRollU3Ed__72_tB6B7F6731FDB6D6C601D3F0544425B5DE05B47A1* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager/<HintDialogue>d__73::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CHintDialogueU3Ed__73__ctor_m94B102F2B01586664F5DC32D7986BF0494BF03C7 (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void UIManager/<HintDialogue>d__73::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CHintDialogueU3Ed__73_System_IDisposable_Dispose_m5EDFD95290AAC7EFFF5D71AADF4040E2F8010613 (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UIManager/<HintDialogue>d__73::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CHintDialogueU3Ed__73_MoveNext_m42762DD9069E7FE09F96B1528708BA1FDB9B4FD9 (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* V_1 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_1 = __this->___U3CU3E4__this_2;
		V_1 = L_1;
		int32_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		return (bool)0;
	}

IL_0017:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// GameManager.NeedDialogueBoxHint = false;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		GameManager_set_NeedDialogueBoxHint_m0B8BBB24C02B9D699559C94865BD6C63667F5884_inline((bool)0, NULL);
		// yield return _hintDelay;
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_4 = V_1;
		NullCheck(L_4);
		WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* L_5 = L_4->____hintDelay_47;
		__this->___U3CU3E2__current_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_5);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0039:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// if (_isDialogueBoxOpen)
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_6 = V_1;
		NullCheck(L_6);
		bool L_7 = L_6->____isDialogueBoxOpen_40;
		if (!L_7)
		{
			goto IL_0064;
		}
	}
	{
		// _dialogueBox.transform.GetChild(0).gameObject.SetActive(true);
		UIManager_tB08C4CBABAE258DC8784331E9ED06411200AF648* L_8 = V_1;
		NullCheck(L_8);
		TextMeshProUGUI_t101091AF4B578BB534C92E9D1EEAF0611636D957* L_9 = L_8->____dialogueBox_41;
		NullCheck(L_9);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_10;
		L_10 = TMP_Text_get_transform_m6BD41E08BFCFCE722DFCE4627626AD60CA99CCA8(L_9, NULL);
		NullCheck(L_10);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_11;
		L_11 = Transform_GetChild_mE686DF0C7AAC1F7AEF356967B1C04D8B8E240EAF(L_10, 0, NULL);
		NullCheck(L_11);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_12;
		L_12 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_11, NULL);
		NullCheck(L_12);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_12, (bool)1, NULL);
	}

IL_0064:
	{
		// }
		return (bool)0;
	}
}
// System.Object UIManager/<HintDialogue>d__73::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CHintDialogueU3Ed__73_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m066937CCC9C61AF021EB3B09AB834851F232C3E3 (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UIManager/<HintDialogue>d__73::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CHintDialogueU3Ed__73_System_Collections_IEnumerator_Reset_m4D107AF061074F6CFCBE2DB4995C1C468C580453 (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CHintDialogueU3Ed__73_System_Collections_IEnumerator_Reset_m4D107AF061074F6CFCBE2DB4995C1C468C580453_RuntimeMethod_var)));
	}
}
// System.Object UIManager/<HintDialogue>d__73::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CHintDialogueU3Ed__73_System_Collections_IEnumerator_get_Current_mC015772341E11243E3BB70E881202DFD5DC51303 (U3CHintDialogueU3Ed__73_t94DC87884AB7EC32C2BC8D063EE25D27A92F8DE2* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsAudioEnabled_m89BB8BC284997DB0FC96A9405C1B035E984C72E1_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get => _isAudioEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isAudioEnabled_46;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsMusicEnabled_mD149DDFF2ABF807F087BB4D6DA0625F0C8D55065_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get => _isMusicEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isMusicEnabled_47;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsHapticEnabled_m64A912E276482E96D33E589E15B102FA68140AC5_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get => _isHapticEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isHapticEnabled_48;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsTutorialsEnabled_m2DCFC9B855219403A47C511B56C3E33EF7C35314_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get => _isTutorialsEnabled;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isTutorialsEnabled_49;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsAudioEnabled_mF8233819F6804D705F704141A489FC0E56D97D62_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// set => _isAudioEnabled = value;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isAudioEnabled_46 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsMusicEnabled_m32A5D2E12A9CD4D37B4DE1C06A1B79F53759575D_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// set => _isMusicEnabled = value;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isMusicEnabled_47 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsHapticEnabled_m32528E40700F774A8501FA6E2FDF22FE25F907D7_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// set => _isHapticEnabled = value;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isHapticEnabled_48 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsTutorialsEnabled_m5F855CEEE242B7D1F3181362EAC2C6CF50E589E1_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// set => _isTutorialsEnabled = value;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isTutorialsEnabled_49 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_RequiredStars_m251E924B52D1C69A6C9D718C0EA6F392B0A79FEE_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static int RequiredStars => _requiredStars;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____requiredStars_37;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_CompassionateStars_mC10D44463CFC587C028B958A747A6A7BF8AFB799_inline (GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1* __this, const RuntimeMethod* method) 
{
	{
		// get => _compassionateStars;
		int32_t L_0 = __this->____compassionateStars_21;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool DialogueManager_get_IsQuery_mCB820DB1AE6081487F94B1108B87FBACF7816DD8_inline (DialogueManager_t0B7E28ED7AE6A84E91E00B74AAA9176445ABD241* __this, const RuntimeMethod* method) 
{
	{
		// public bool IsQuery => _isQuery;
		bool L_0 = __this->____isQuery_7;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_NeedDialogueBoxHint_m2D72B960A1B248627A87A7CF0F5F5E8728C67C55_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get => _needDialogueBoxHint;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____needDialogueBoxHint_52;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_AcquiredStars_mCDE7E0F1971DF50982BFCB430E40711A76496222_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get => _acquiredStars;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____acquiredStars_36;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_CurrentScore_mCFD308B1545586CD81E7B5051BFE261008BD484C_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get => _currentScore;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____currentScore_38;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GameManager_get_StageAnswerQuality_mCD07E8FED832C6E4AA0E6C875D02939D2CD92E16_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static Answer StageAnswerQuality => _stageAnswerQuality;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		int32_t L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____stageAnswerQuality_62;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* GameManager_get_CurrentStageDialogue_m298FEF5012933892CF97212C2D056F0252EA3BA7_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static StageDialogue CurrentStageDialogue => _currentStageDialogue;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		StageDialogue_tBA2B5356CEA12257128FFD89198EE98AB4E37CFD* L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____currentStageDialogue_13;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Mathf_Min_m888083F74FF5655778F0403BB5E9608BEFDEA8CB_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B3_0 = 0;
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0008;
		}
	}
	{
		int32_t L_2 = ___1_b;
		G_B3_0 = L_2;
		goto IL_0009;
	}

IL_0008:
	{
		int32_t L_3 = ___0_a;
		G_B3_0 = L_3;
	}

IL_0009:
	{
		V_0 = G_B3_0;
		goto IL_000c;
	}

IL_000c:
	{
		int32_t L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* __this, float ___0_r, float ___1_g, float ___2_b, float ___3_a, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_r;
		__this->___r_0 = L_0;
		float L_1 = ___1_g;
		__this->___g_1 = L_1;
		float L_2 = ___2_b;
		__this->___b_2 = L_2;
		float L_3 = ___3_a;
		__this->___a_3 = L_3;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GameManager_get_IsGameOver_mF865E823B3B8F11883D33D15152D2680CE20AD33_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool IsGameOver => _isGameOver;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		bool L_0 = ((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isGameOver_56;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_IsStageMenuOpen_m8A712BA74947AD95FA3444508E8533F8644F3CAD_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// set => _isStageMenuOpen = value;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____isStageMenuOpen_50 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Color_tD001788D726C3A7F1379BEED0260B9591F440C1F Color_get_black_mB50217951591A045844C61E7FF31EEE3FEF16737_inline (const RuntimeMethod* method) 
{
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_0;
		memset((&L_0), 0, sizeof(L_0));
		Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline((&L_0), (0.0f), (0.0f), (0.0f), (1.0f), /*hidden argument*/NULL);
		V_0 = L_0;
		goto IL_001d;
	}

IL_001d:
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GameManager_set_NeedDialogueBoxHint_m0B8BBB24C02B9D699559C94865BD6C63667F5884_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// set => _needDialogueBoxHint = value;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var);
		((GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_StaticFields*)il2cpp_codegen_static_fields_for(GameManager_t30E6C4E0762DB9731151D46B84CE7BE7BDCD8CE1_il2cpp_TypeInfo_var))->____needDialogueBoxHint_52 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = (RuntimeObject*)__this->____current_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = (int32_t)__this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		if (!true)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_1 = (int32_t)__this->____size_2;
		V_0 = L_1;
		__this->____size_2 = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)__this->____items_1;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_0035:
	{
		__this->____size_2 = 0;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = (int32_t)__this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)__this->____items_1;
		V_0 = L_1;
		int32_t L_2 = (int32_t)__this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mAC3C34BA1905AB5B79E483CD9BB082B7D667F703_gshared_inline (Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* __this, int32_t ___0_obj, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
