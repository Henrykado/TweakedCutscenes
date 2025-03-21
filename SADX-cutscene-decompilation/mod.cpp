#include "SADXModLoader.h"
#include "SADXEventFunctions.h"
#include "SADXEventList.h"
#include "SADXEventVariables.h"
#include "IniFile.hpp"
#include "FunctionHook.h"
#include "OBJECT_SonicPointingFinger.h"

bool removeOutroRun = false;
bool removeCrashPlane = false;
bool tenseCrashMusic = false;
bool worriedTails = false;
bool knucklesWalk = true;
bool betaDash = false;
bool crazyRobo = false;
bool muffledAmy = true;
bool skipSecondJump = true;
bool disableFMVRender = false;

bool disableAmyDressMorph = false;

//FunctionHook<void, ObjectMaster*> SoundManager_Delete_h(SoundManager_Delete);

extern "C"
{
	//void SoundManager_Delete_r(ObjectMaster* objm)
	//{
	//	return;
	//	SoundManager_Delete_h.Original(objm);
	//}
	FunctionPointer(void, AddDressMorphs, (ObjectMaster* a1), 0x485F40);
	FunctionHook<void, ObjectMaster*> AddDressMorphs_h(AddDressMorphs);

	FunctionHook<void> DoCrashingEggCarrierCutsceneThing_h(DoCrashingEggCarrierCutsceneThing);

	void AddDressMorphs_r(ObjectMaster* a1)
	{
		if (disableAmyDressMorph) return;
		AddDressMorphs_h.Original(a1);
	}
	
	void DoCrashingEggCarrierCutsceneThing_r()
	{
		if (disableFMVRender) return;
		DoCrashingEggCarrierCutsceneThing_h.Original();
	}

	void LoadPlaneTexture()
	{
		njSetTexture(&EV_S_T2C_BODY_TEXLIST);
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		AddDressMorphs_h.Hook(AddDressMorphs_r);
		DoCrashingEggCarrierCutsceneThing_h.Hook(DoCrashingEggCarrierCutsceneThing_r);
		WriteCall((void*)0x6F9314, LoadPlaneTexture);

		if (GetModuleHandle(L"SA1_Chars") != nullptr)
		{
			WriteData<NJS_OBJECT>((NJS_OBJECT*)0x2DD8708, OBJECT_SonicPointingFinger);
		}

		//SoundManager_Delete_h.Hook(SoundManager_Delete_r);

		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		removeOutroRun = config->getBool("", "removeOutroRun", false);
		//removeCrashPlane = config->getBool("", "removeCrashPlane", false);
		tenseCrashMusic = config->getBool("", "tenseCrashMusic", false);
		worriedTails = config->getBool("", "worriedTails", false);
		knucklesWalk = config->getBool("", "knucklesWalk", true);
		betaDash = config->getBool("", "betaDash", false);
		crazyRobo = config->getBool("", "crazyRobo", false);
		muffledAmy = config->getBool("", "muffledAmy", true);
		skipSecondJump = config->getBool("", "skipSecondJump", true);
		disableFMVRender = config->getBool("", "disableFMVRender", false);
		delete config;

		if (muffledAmy)
		{
			helperFunctions.ReplaceFile("SoundData\\VOICE_JP\\WMA\\0517.adx", "system\\sounddata\\0517_jp.adx");
			helperFunctions.ReplaceFile("SoundData\\VOICE_US\\WMA\\0517.adx", "system\\sounddata\\0517_us.adx");
		}

		/* ***DELETE ANY EVENTS YOU DON'T USE***
		* It makes build time a lot faster and you won't run into problems with other mods from overwriting all of them.
		* texTbls must end with 0 or the game will crash.
		*/

		//Main event code
		//CutsceneDataList[0x0001]->Function = ev0001_s_intro;
		CutsceneDataList[0x0002]->Function = ev0002_s_chaos0defeated;
		CutsceneDataList[0x0003]->Function = ev0003_s_tailscrash;
		CutsceneDataList[0x0006]->Function = ev0006_s_poolsidewithtails;
		CutsceneDataList[0x0007]->Function = ev0007_s_egghornetintro;
		CutsceneDataList[0x0008]->Function = ev0008_s_chaos1;
		CutsceneDataList[0x0009]->Function = ev0009_s_aftercasinopolis;
		CutsceneDataList[0x000B]->Function = ev000B_s_beforechaos4;
		CutsceneDataList[0x000C]->Function = ev000C_s_afterchaos4;
		CutsceneDataList[0x000D]->Function = ev000D_s_tornado1;
		CutsceneDataList[0x0011]->Function = ev0011_s_fallingtoSS;
		CutsceneDataList[0x0012]->Function = ev0012_s_meetingamy;
		CutsceneDataList[0x0013]->Function = ev0013_s_beforetwinklepark;
		//CutsceneDataList[0x0014]->Function = ev0014_s_aftertwinklepark;
		//CutsceneDataList[0x0015]->Function = ev0015_s_chasingzero;
		CutsceneDataList[0x0016]->Function = ev0016_s_zeroboardsec;
		CutsceneDataList[0x0017]->Function = ev0017_s_tailsreunion;
		CutsceneDataList[0x001A]->Function = ev001A_s_eggmantakesbirdie;
		CutsceneDataList[0x001B]->Function = ev001B_s_aftergamma;
		CutsceneDataList[0x001C]->Function = ev001C_s_beforechaos6;
		CutsceneDataList[0x001D]->Function = ev001D_s_afterchaos6;
		CutsceneDataList[0x001E]->Function = ev001E_s_lostworld;
		CutsceneDataList[0x0020]->Function = ev0020_s_mural;
		//CutsceneDataList[0x0021]->Function = ev0021_s_enterpast;
		CutsceneDataList[0x0022]->Function = ev0022_s_pastaltar;
		CutsceneDataList[0x0023]->Function = ev0023_s_afterpast;
		CutsceneDataList[0x0024]->Function = ev0024_s_eggviper;
		CutsceneDataList[0x0026]->Function = ev0026_s_outro;
		CutsceneDataList[0x0028]->Function = ev0028_s_sonicvsknuckles;
		//CutsceneDataList[0x0029]->Function = ev0029_s_eclanding;
		CutsceneDataList[0x002A]->Function = ev002A_s_casinowake;
		//CutsceneDataList[0x002B]->Function = ev002B_s_beforechaos0;
		//CutsceneDataList[0x0030]->Function = ev0030_t_intro;*/
		CutsceneDataList[0x0031]->Function = ev0031_t_emeraldcoast;
		CutsceneDataList[0x0032]->Function = ev0032_t_meetingsonic;
		CutsceneDataList[0x0033]->Function = ev0033_t_egghornet;
		CutsceneDataList[0x0034]->Function = ev0034_t_chaos1;
		CutsceneDataList[0x0035]->Function = ev0035_t_aftercasinopolis;
		CutsceneDataList[0x0038]->Function = ev0038_t_vsknuckles;
		CutsceneDataList[0x0039]->Function = ev0039_t_beforechaos4;
		CutsceneDataList[0x003A]->Function = ev003A_t_afterchaos4;
		CutsceneDataList[0x003B]->Function = ev003B_t_tornado1;
		CutsceneDataList[0x003E]->Function = ev003E_t_flashback;
		CutsceneDataList[0x0040]->Function = ev0040_t_afterflashback;
		CutsceneDataList[0x0042]->Function = ev0042_t_froggyjungle;
		CutsceneDataList[0x0044]->Function = ev0044_t_enterpast;
		CutsceneDataList[0x0045]->Function = ev0045_t_tikal;
		CutsceneDataList[0x0046]->Function = ev0046_t_big;
		//CutsceneDataList[0x0047]->Function = ev0047_t_tornado2;
		//CutsceneDataList[0x0048]->Function = ev0048_t_sonicreunion;
		CutsceneDataList[0x004B]->Function = ev004B_t_eggmantakesbirdie;
		CutsceneDataList[0x004C]->Function = ev004C_t_escapecarrier;
		CutsceneDataList[0x004D]->Function = ev004D_t_missile;
		CutsceneDataList[0x004E]->Function = ev004E_t_speedhighway;
		CutsceneDataList[0x0050]->Function = ev0050_t_eggwalker;
		//CutsceneDataList[0x0051]->Function = ev0051_t_walkerdefeated;
		CutsceneDataList[0x0052]->Function = ev0052_t_outro;
		//CutsceneDataList[0x0053]->Function = ev0053_t_fmvplaceholder;
		//CutsceneDataList[0x0054]->Function = ev0054_t_eclanding;
		CutsceneDataList[0x0055]->Function = ev0055_t_sandhill;
		CutsceneDataList[0x0056]->Function = ev0056_t_casinowake;
		//CutsceneDataList[0x0058]->Function = ev0058_a_preintro;
		CutsceneDataList[0x0060]->Function = ev0060_a_intro1;
		CutsceneDataList[0x0061]->Function = ev0061_a_intro2;
		CutsceneDataList[0x0062]->Function = ev0062_a_meetsonic;
		CutsceneDataList[0x0063]->Function = ev0063_a_twinklepark;
		CutsceneDataList[0x0064]->Function = ev0064_a_kidnapped;
		CutsceneDataList[0x0065]->Function = ev0065_a_prison;
		//CutsceneDataList[0x0066]->Function = ev0066_a_hotshelter;
		CutsceneDataList[0x0067]->Function = ev0067_a_past;
		CutsceneDataList[0x0068]->Function = ev0068_a_tikal;
		CutsceneDataList[0x0069]->Function = ev0069_a_eggmantakesbirdie;
		CutsceneDataList[0x006A]->Function = ev006A_a_escapecarrier;
		//CutsceneDataList[0x006B]->Function = ev006B_a_fmvplaceholder;
		//CutsceneDataList[0x006C]->Function = ev006C_a_exitpast;
		CutsceneDataList[0x006D]->Function = ev006D_a_savebirdsbros;
		CutsceneDataList[0x006E]->Function = ev006E_a_junglebase;
		CutsceneDataList[0x006F]->Function = ev006F_a_finalegg;
		CutsceneDataList[0x0070]->Function = ev0070_a_returncarrier;
		CutsceneDataList[0x0071]->Function = ev0071_a_amygetangry;
		CutsceneDataList[0x0072]->Function = ev0072_a_outro;
		CutsceneDataList[0x0075]->Function = ev0075_a_kidnapped2;
		CutsceneDataList[0x0080]->Function = ev0080_k_intro;
		//CutsceneDataList[0x0082]->Function = ev0082_k_beginhunt;
		//CutsceneDataList[0x0083]->Function = ev0083_k_casinopolis;
		//CutsceneDataList[0x0084]->Function = ev0084_k_pastfirst;
		CutsceneDataList[0x0085]->Function = ev0085_k_tikalfather;
		CutsceneDataList[0x0086]->Function = ev0086_k_leavepastfirst;
		CutsceneDataList[0x0087]->Function = ev0087_k_chaos2;
		CutsceneDataList[0x0088]->Function = ev0088_k_eggmantricksknuckles;
		//CutsceneDataList[0x0089]->Function = ev0089_k_chasesonic;
		//CutsceneDataList[0x008A]->Function = ev008A_k_vssonic;
		CutsceneDataList[0x008B]->Function = ev008B_k_chaos4;
		CutsceneDataList[0x008C]->Function = ev008C_k_afterchaos4;
		//CutsceneDataList[0x008D]->Function = ev008D_k_lostpast;
		//CutsceneDataList[0x008E]->Function = ev008E_k_pastsecond;
		CutsceneDataList[0x008F]->Function = ev008F_k_tikalaltar;
		CutsceneDataList[0x0091]->Function = ev0091_k_leavepastsecond;
		CutsceneDataList[0x0092]->Function = ev0092_k_followgamma;
		//CutsceneDataList[0x0094]->Function = ev0094_k_boardec;
		CutsceneDataList[0x0095]->Function = ev0095_k_gotlastpieces;
		//CutsceneDataList[0x0096]->Function = ev0096_k_pastthird;
		//CutsceneDataList[0x0097]->Function = ev0097_k_tikalfire;
		//CutsceneDataList[0x0098]->Function = ev0098_k_leavepastthird;
		CutsceneDataList[0x0099]->Function = ev0099_k_beforechaos6;
		CutsceneDataList[0x009A]->Function = ev009A_k_glubglub;
		CutsceneDataList[0x009B]->Function = ev009B_k_afterchaos6;
		//CutsceneDataList[0x009C]->Function = ev009C_k_fmvplaceholder;
		CutsceneDataList[0x009D]->Function = ev009D_k_restoreme;
		//CutsceneDataList[0x009F]->Function = ev009F_k_outro;
		CutsceneDataList[0x00A0]->Function = ev00A0_k_eggmanhotel;
		//CutsceneDataList[0x00B0]->Function = ev00B0_e_intro;
		//CutsceneDataList[0x00B1]->Function = ev00B1_e_finalegg;
		CutsceneDataList[0x00B2]->Function = ev00B2_e_afterfinalegg;
		//CutsceneDataList[0x00B3]->Function = ev00B3_e_uselessmachine;
		CutsceneDataList[0x00B4]->Function = ev00B4_e_e101;
		CutsceneDataList[0x00B5]->Function = ev00B5_e_betadefeated;
		CutsceneDataList[0x00B7]->Function = ev00B7_e_fanfare;
		//CutsceneDataList[0x00B8]->Function = ev00B8_e_emeraldcoast;
		//CutsceneDataList[0x00B9]->Function = ev00B9_e_past;
		CutsceneDataList[0x00BA]->Function = ev00BA_e_tikal;
		CutsceneDataList[0x00BB]->Function = ev00BB_e_deliverfrog;
		CutsceneDataList[0x00BC]->Function = ev00BC_e_enterwrongroom;
		CutsceneDataList[0x00BD]->Function = ev00BD_e_e101factory;
		CutsceneDataList[0x00BE]->Function = ev00BE_e_exitwrongroom;
		CutsceneDataList[0x00BF]->Function = ev00BF_e_prison;
		CutsceneDataList[0x00C0]->Function = ev00C0_e_reportrear;
		CutsceneDataList[0x00C1]->Function = ev00C1_e_sonic;
		CutsceneDataList[0x00C2]->Function = ev00C2_e_escapecarrier;
		//CutsceneDataList[0x00C3]->Function = ev00C3_e_objectivechanged;
		//CutsceneDataList[0x00C5]->Function = ev00C5_e_rememberbros;
		CutsceneDataList[0x00C7]->Function = ev00C7_e_outro;
		CutsceneDataList[0x00D0]->Function = ev00D0_b_intro;
		CutsceneDataList[0x00D1]->Function = ev00D1_b_stationsquare;
		CutsceneDataList[0x00D2]->Function = ev00D2_b_car;
		CutsceneDataList[0x00D3]->Function = ev00D3_b_tails;
		CutsceneDataList[0x00D4]->Function = ev00D4_b_emeraldcoast;
		CutsceneDataList[0x00D8]->Function = ev00D8_b_eggcarrier;
		CutsceneDataList[0x00D9]->Function = ev00D9_b_hotsheltertank;
		//CutsceneDataList[0x00DA]->Function = ev00DA_b_enterpast;
		//CutsceneDataList[0x00DB]->Function = ev00DB_b_past;
		CutsceneDataList[0x00DC]->Function = ev00DC_b_tikal;
		CutsceneDataList[0x00DD]->Function = ev00DD_b_leavepast;
		CutsceneDataList[0x00DE]->Function = ev00DE_b_chaos6;
		//CutsceneDataList[0x00DF]->Function = ev00DF_b_chaos6defeated;
		//CutsceneDataList[0x00E0]->Function = ev00E0_b_tornado2;
		//CutsceneDataList[0x00E1]->Function = ev00E1_b_fmvplaceholder;
		CutsceneDataList[0x00E2]->Function = ev00E2_b_outro;
		//CutsceneDataList[0x00E3]->Function = ev00E3_b_froggyhotel;
		CutsceneDataList[0x00F0]->Function = ev00F0_l_intro;
		CutsceneDataList[0x00F2]->Function = ev00F2_l_eggman;
		CutsceneDataList[0x00F3]->Function = ev00F3_l_knuckles;
		CutsceneDataList[0x00F4]->Function = ev00F4_l_sonicwakesup;
		CutsceneDataList[0x00F5]->Function = ev00F5_l_sonicfindsknuckles;
		//CutsceneDataList[0x00F6]->Function = ev00F6_l_past;
		CutsceneDataList[0x00F7]->Function = ev00F7_l_tikalplead;
		//CutsceneDataList[0x00F8]->Function = ev00F8_l_tikalsealschaos;
		CutsceneDataList[0x00F9]->Function = ev00F9_l_snoozecruise;
		//CutsceneDataList[0x00FA]->Function = ev00FA_l_tornado2;
		CutsceneDataList[0x00FB]->Function = ev00FB_l_tikalwakesup;
		CutsceneDataList[0x00FD]->Function = ev00FD_l_perfectchaos;
		CutsceneDataList[0x00FE]->Function = ev00FE_l_outro;
		CutsceneDataList[0x00FF]->Function = ev00FF_l_supersonic;
		CutsceneDataList[0x0100]->Function = ev0100_s_ecafterlanding;
		CutsceneDataList[0x0101]->Function = ev0101_s_ecfools;
		CutsceneDataList[0x0102]->Function = ev0102_s_ecaftertransforming;
		//CutsceneDataList[0x0103]->Function = ev0103_s_skydeck;
		CutsceneDataList[0x0104]->Function = ev0104_s_afterskydeck;
		//CutsceneDataList[0x0106]->Function = ev0106_s_originalshape;
		//CutsceneDataList[0x0107]->Function = ev0107_s_alertcancelled;
		CutsceneDataList[0x0110]->Function = ev0110_t_ecafterlanding;
		CutsceneDataList[0x0111]->Function = ev0111_t_ecfools;
		CutsceneDataList[0x0112]->Function = ev0112_t_ecaftertransforming;
		//CutsceneDataList[0x0113]->Function = ev0113_t_skydeck;
		CutsceneDataList[0x0114]->Function = ev0114_t_afterskydeck;
		CutsceneDataList[0x0120]->Function = ev0120_k_ectransform1;
		CutsceneDataList[0x0121]->Function = ev0121_k_ectransform2;
		CutsceneDataList[0x0122]->Function = ev0122_k_outsideskydeck;
		//CutsceneDataList[0x0130]->Function = ev0130_a_hedgehoghammer;
		//CutsceneDataList[0x0131]->Function = ev0131_a_hedgehoghammerwin;
		//CutsceneDataList[0x0140]->Function = ev0140_e_findjetbooster;
		//CutsceneDataList[0x0141]->Function = ev0141_e_hotshelter;
		if (!crazyRobo) CutsceneDataList[0x0142]->Function = ev0142_e_betamk2;
		//CutsceneDataList[0x0150]->Function = ev0150_b_alertcancelled;
		CutsceneDataList[0x0160]->Function = ev0160_l_chaosgetangry;
		/*CutsceneDataList[0x0165]->Function = ev0165_s_crystalring;
		CutsceneDataList[0x0166]->Function = ev0166_s_lightshoes;
		CutsceneDataList[0x0167]->Function = ev0167_s_ancientlight;
		CutsceneDataList[0x0168]->Function = ev0168_t_jetanklet;
		CutsceneDataList[0x0169]->Function = ev0169_t_rhythmbadge;
		CutsceneDataList[0x016A]->Function = ev016A_k_fightgloves;
		CutsceneDataList[0x016B]->Function = ev016B_k_shovelclaw;
		CutsceneDataList[0x016C]->Function = ev016C_a_longhammer;
		CutsceneDataList[0x016D]->Function = ev016D_a_warriorfeather;
		CutsceneDataList[0x016E]->Function = ev016E_e_laserblaster;
		CutsceneDataList[0x016F]->Function = ev016F_e_jetbooster;
		CutsceneDataList[0x0170]->Function = ev0170_b_powerrod;
		CutsceneDataList[0x0171]->Function = ev0171_b_lifebelt;
		CutsceneDataList[0x0176]->Function = ev0176_s_icestone;
		CutsceneDataList[0x0177]->Function = ev0177_t_icestone;
		CutsceneDataList[0x0178]->Function = ev0178_b_icestone;
		CutsceneDataList[0x0179]->Function = ev0179_s_idcard;
		CutsceneDataList[0x017A]->Function = ev017A_s_angelislandwall;
		CutsceneDataList[0x017B]->Function = ev017B_t_angelislandwall;
		CutsceneDataList[0x017C]->Function = ev017C_e_angelislandwall;*/
		//CutsceneDataList[0x0180]->Function = ev0180_s_redmountainintro;

		//PVMs to load for each event.
		//CutsceneDataList[0x0001]->Textures = texTbl_ev0001;
		CutsceneDataList[0x0002]->Textures = texTbl_ev0002;
		CutsceneDataList[0x0003]->Textures = texTbl_ev0003;
		CutsceneDataList[0x0006]->Textures = texTbl_ev0006;
		CutsceneDataList[0x0007]->Textures = texTbl_ev0007;
		CutsceneDataList[0x0008]->Textures = texTbl_ev0008;
		CutsceneDataList[0x0009]->Textures = texTbl_ev0009;
		CutsceneDataList[0x000B]->Textures = texTbl_ev000B;
		CutsceneDataList[0x000C]->Textures = texTbl_ev000C;
		CutsceneDataList[0x000D]->Textures = texTbl_ev000D;
		CutsceneDataList[0x0011]->Textures = texTbl_ev0011;
		CutsceneDataList[0x0012]->Textures = texTbl_ev0012;
		CutsceneDataList[0x0013]->Textures = texTbl_ev0013;
		//CutsceneDataList[0x0014]->Textures = texTbl_ev0014;
		//CutsceneDataList[0x0015]->Textures = texTbl_ev0015;
		CutsceneDataList[0x0016]->Textures = texTbl_ev0016;
		CutsceneDataList[0x0017]->Textures = texTbl_ev0017;
		CutsceneDataList[0x001A]->Textures = texTbl_ev001A;
		CutsceneDataList[0x001B]->Textures = texTbl_ev001B;
		CutsceneDataList[0x001C]->Textures = texTbl_ev001C;
		CutsceneDataList[0x001D]->Textures = texTbl_ev001D;
		CutsceneDataList[0x001E]->Textures = texTbl_ev001E;
		CutsceneDataList[0x0020]->Textures = texTbl_ev0020;
		//CutsceneDataList[0x0021]->Textures = texTbl_ev0021;
		CutsceneDataList[0x0022]->Textures = texTbl_ev0022;
		CutsceneDataList[0x0023]->Textures = texTbl_ev0023;
		CutsceneDataList[0x0024]->Textures = texTbl_ev0024;
		CutsceneDataList[0x0026]->Textures = texTbl_ev0026;
		CutsceneDataList[0x0028]->Textures = texTbl_ev0028;
		//CutsceneDataList[0x0029]->Textures = texTbl_ev0029;
		CutsceneDataList[0x002A]->Textures = texTbl_ev002A;
		//CutsceneDataList[0x002B]->Textures = texTbl_ev002B;
		//CutsceneDataList[0x0030]->Textures = texTbl_ev0030;
		CutsceneDataList[0x0031]->Textures = texTbl_ev0031;
		CutsceneDataList[0x0032]->Textures = texTbl_ev0032;
		CutsceneDataList[0x0033]->Textures = texTbl_ev0033;
		CutsceneDataList[0x0034]->Textures = texTbl_ev0034;
		CutsceneDataList[0x0035]->Textures = texTbl_ev0035;
		CutsceneDataList[0x0038]->Textures = texTbl_ev0038;
		CutsceneDataList[0x0039]->Textures = texTbl_ev0039;
		CutsceneDataList[0x003A]->Textures = texTbl_ev003A;
		CutsceneDataList[0x003B]->Textures = texTbl_ev003B;
		CutsceneDataList[0x003E]->Textures = texTbl_ev003E;
		CutsceneDataList[0x0040]->Textures = texTbl_ev0040;
		CutsceneDataList[0x0042]->Textures = texTbl_ev0042;
		CutsceneDataList[0x0044]->Textures = texTbl_ev0044;
		CutsceneDataList[0x0045]->Textures = texTbl_ev0045;
		CutsceneDataList[0x0046]->Textures = texTbl_ev0046;
		//CutsceneDataList[0x0047]->Textures = texTbl_ev0047;
		//CutsceneDataList[0x0048]->Textures = texTbl_ev0048;
		CutsceneDataList[0x004B]->Textures = texTbl_ev004B;
		CutsceneDataList[0x004C]->Textures = texTbl_ev004C;
		CutsceneDataList[0x004D]->Textures = texTbl_ev004D;
		CutsceneDataList[0x004E]->Textures = texTbl_ev004E;
		CutsceneDataList[0x0050]->Textures = texTbl_ev0050;
		//CutsceneDataList[0x0051]->Textures = texTbl_ev0051;
		CutsceneDataList[0x0052]->Textures = texTbl_ev0052;
		//CutsceneDataList[0x0053]->Textures = texTbl_ev0053;
		//CutsceneDataList[0x0054]->Textures = texTbl_ev0054;
		CutsceneDataList[0x0055]->Textures = texTbl_ev0055;
		CutsceneDataList[0x0056]->Textures = texTbl_ev0056;
		//CutsceneDataList[0x0058]->Textures = texTbl_ev0058;
		CutsceneDataList[0x0060]->Textures = texTbl_ev0060;
		CutsceneDataList[0x0061]->Textures = texTbl_ev0061;
		CutsceneDataList[0x0062]->Textures = texTbl_ev0062;
		CutsceneDataList[0x0063]->Textures = texTbl_ev0063;
		CutsceneDataList[0x0064]->Textures = texTbl_ev0064;
		CutsceneDataList[0x0065]->Textures = texTbl_ev0065;
		//CutsceneDataList[0x0066]->Textures = texTbl_ev0066;
		CutsceneDataList[0x0067]->Textures = texTbl_ev0067;
		CutsceneDataList[0x0068]->Textures = texTbl_ev0068;
		CutsceneDataList[0x0069]->Textures = texTbl_ev0069;
		CutsceneDataList[0x006A]->Textures = texTbl_ev006A;
		//CutsceneDataList[0x006B]->Textures = texTbl_ev006B;
		//CutsceneDataList[0x006C]->Textures = texTbl_ev006C;
		CutsceneDataList[0x006E]->Textures = texTbl_ev006E;
		CutsceneDataList[0x006F]->Textures = texTbl_ev006F;
		CutsceneDataList[0x0070]->Textures = texTbl_ev0070;
		CutsceneDataList[0x0071]->Textures = texTbl_ev0071;
		CutsceneDataList[0x0072]->Textures = texTbl_ev0072;
		CutsceneDataList[0x0075]->Textures = texTbl_ev0075;
		CutsceneDataList[0x0080]->Textures = texTbl_ev0080;
		//CutsceneDataList[0x0082]->Textures = texTbl_ev0082;
		//CutsceneDataList[0x0083]->Textures = texTbl_ev0083;
		//CutsceneDataList[0x0084]->Textures = texTbl_ev0084;
		CutsceneDataList[0x0085]->Textures = texTbl_ev0085;
		CutsceneDataList[0x0086]->Textures = texTbl_ev0086;
		CutsceneDataList[0x0087]->Textures = texTbl_ev0087;
		CutsceneDataList[0x0088]->Textures = texTbl_ev0088;
		//CutsceneDataList[0x0089]->Textures = texTbl_ev0089;
		//CutsceneDataList[0x008A]->Textures = texTbl_ev008A;
		CutsceneDataList[0x008B]->Textures = texTbl_ev008B;
		CutsceneDataList[0x008C]->Textures = texTbl_ev008C;
		//CutsceneDataList[0x008D]->Textures = texTbl_ev008D;
		//CutsceneDataList[0x008E]->Textures = texTbl_ev008E;
		CutsceneDataList[0x008F]->Textures = texTbl_ev008F;
		CutsceneDataList[0x0091]->Textures = texTbl_ev0091;
		CutsceneDataList[0x0092]->Textures = texTbl_ev0092;
		//CutsceneDataList[0x0094]->Textures = texTbl_ev0094;
		CutsceneDataList[0x0095]->Textures = texTbl_ev0095;
		//CutsceneDataList[0x0096]->Textures = texTbl_ev0096;
		//CutsceneDataList[0x0097]->Textures = texTbl_ev0097;
		//CutsceneDataList[0x0098]->Textures = texTbl_ev0098;
		CutsceneDataList[0x0099]->Textures = texTbl_ev0099;
		CutsceneDataList[0x009A]->Textures = texTbl_ev009A;
		CutsceneDataList[0x009B]->Textures = texTbl_ev009B;
		//CutsceneDataList[0x009C]->Textures = texTbl_ev009C;
		CutsceneDataList[0x009D]->Textures = texTbl_ev009D;
		//CutsceneDataList[0x009F]->Textures = texTbl_ev009F;
		CutsceneDataList[0x00A0]->Textures = texTbl_ev00A0;
		//CutsceneDataList[0x00B0]->Textures = texTbl_ev00B0;
		//CutsceneDataList[0x00B1]->Textures = texTbl_ev00B1;
		CutsceneDataList[0x00B2]->Textures = texTbl_ev00B2;
		//CutsceneDataList[0x00B3]->Textures = texTbl_ev00B3;
		CutsceneDataList[0x00B4]->Textures = texTbl_ev00B4;
		CutsceneDataList[0x00B5]->Textures = texTbl_ev00B5;
		CutsceneDataList[0x00B7]->Textures = texTbl_ev00B7;
		//CutsceneDataList[0x00B8]->Textures = texTbl_ev00B8;
		//CutsceneDataList[0x00B9]->Textures = texTbl_ev00B9;
		CutsceneDataList[0x00BA]->Textures = texTbl_ev00BA;
		CutsceneDataList[0x00BB]->Textures = texTbl_ev00BB;
		CutsceneDataList[0x00BC]->Textures = texTbl_ev00BC;
		CutsceneDataList[0x00BD]->Textures = texTbl_ev00BD;
		CutsceneDataList[0x00BE]->Textures = texTbl_ev00BE;
		CutsceneDataList[0x00BF]->Textures = texTbl_ev00BF;
		CutsceneDataList[0x00C0]->Textures = texTbl_ev00C0;
		CutsceneDataList[0x00C1]->Textures = texTbl_ev00C1;
		CutsceneDataList[0x00C2]->Textures = texTbl_ev00C2;
		//CutsceneDataList[0x00C3]->Textures = texTbl_ev00C3;
		//CutsceneDataList[0x00C5]->Textures = texTbl_ev00C5;
		CutsceneDataList[0x00C7]->Textures = texTbl_ev00C7;
		CutsceneDataList[0x00D0]->Textures = texTbl_ev00D0;
		CutsceneDataList[0x00D1]->Textures = texTbl_ev00D1;
		CutsceneDataList[0x00D2]->Textures = texTbl_ev00D2;
		CutsceneDataList[0x00D3]->Textures = texTbl_ev00D3;
		CutsceneDataList[0x00D4]->Textures = texTbl_ev00D4;
		CutsceneDataList[0x00D8]->Textures = texTbl_ev00D8;
		CutsceneDataList[0x00D9]->Textures = texTbl_ev00D9;
		//CutsceneDataList[0x00DA]->Textures = texTbl_ev00DA;
		//CutsceneDataList[0x00DB]->Textures = texTbl_ev00DB;
		CutsceneDataList[0x00DC]->Textures = texTbl_ev00DC;
		CutsceneDataList[0x00DD]->Textures = texTbl_ev00DD;
		CutsceneDataList[0x00DE]->Textures = texTbl_ev00DE;
		//CutsceneDataList[0x00DF]->Textures = texTbl_ev00DF;
		//CutsceneDataList[0x00E0]->Textures = texTbl_ev00E0;
		//CutsceneDataList[0x00E1]->Textures = texTbl_ev00E1;
		CutsceneDataList[0x00E2]->Textures = texTbl_ev00E2;
		//CutsceneDataList[0x00E3]->Textures = texTbl_ev00E3;
		CutsceneDataList[0x00F0]->Textures = texTbl_ev00F0;
		CutsceneDataList[0x00F2]->Textures = texTbl_ev00F2;
		CutsceneDataList[0x00F3]->Textures = texTbl_ev00F3;
		CutsceneDataList[0x00F4]->Textures = texTbl_ev00F4;
		CutsceneDataList[0x00F5]->Textures = texTbl_ev00F5;
		//CutsceneDataList[0x00F6]->Textures = texTbl_ev00F6;
		CutsceneDataList[0x00F7]->Textures = texTbl_ev00F7;
		//CutsceneDataList[0x00F8]->Textures = texTbl_ev00F8;
		CutsceneDataList[0x00F9]->Textures = texTbl_ev00F9;
		//CutsceneDataList[0x00FA]->Textures = texTbl_ev00FA;
		CutsceneDataList[0x00FB]->Textures = texTbl_ev00FB;
		CutsceneDataList[0x00FD]->Textures = texTbl_ev00FD;
		CutsceneDataList[0x00FE]->Textures = texTbl_ev00FE;
		CutsceneDataList[0x00FF]->Textures = texTbl_ev00FF;
		CutsceneDataList[0x0100]->Textures = texTbl_ev0100;
		CutsceneDataList[0x0101]->Textures = texTbl_ev0101;
		CutsceneDataList[0x0102]->Textures = texTbl_ev0102;
		//CutsceneDataList[0x0103]->Textures = texTbl_ev0103;
		CutsceneDataList[0x0104]->Textures = texTbl_ev0104;
		//CutsceneDataList[0x0106]->Textures = texTbl_ev0106;
		//CutsceneDataList[0x0107]->Textures = texTbl_ev0107;
		CutsceneDataList[0x0110]->Textures = texTbl_ev0110;
		CutsceneDataList[0x0111]->Textures = texTbl_ev0111;
		CutsceneDataList[0x0112]->Textures = texTbl_ev0112;
		//CutsceneDataList[0x0113]->Textures = texTbl_ev0113;
		CutsceneDataList[0x0114]->Textures = texTbl_ev0114;
		CutsceneDataList[0x0120]->Textures = texTbl_ev0120;
		CutsceneDataList[0x0121]->Textures = texTbl_ev0121;
		CutsceneDataList[0x0122]->Textures = texTbl_ev0122;
		//CutsceneDataList[0x0130]->Textures = texTbl_ev0130;
		//CutsceneDataList[0x0131]->Textures = texTbl_ev0131;
		//CutsceneDataList[0x0140]->Textures = texTbl_ev0140;
		//CutsceneDataList[0x0141]->Textures = texTbl_ev0141;
		if (!crazyRobo) CutsceneDataList[0x0142]->Textures = texTbl_ev0142;
		//CutsceneDataList[0x0150]->Textures = texTbl_ev0150;
		CutsceneDataList[0x0160]->Textures = texTbl_ev0160;
		/*CutsceneDataList[0x0165]->Textures = texTbl_ev0165;
		CutsceneDataList[0x0166]->Textures = texTbl_ev0166;
		CutsceneDataList[0x0167]->Textures = texTbl_ev0167;
		CutsceneDataList[0x0168]->Textures = texTbl_ev0168;
		CutsceneDataList[0x0169]->Textures = texTbl_ev0169;
		CutsceneDataList[0x016A]->Textures = texTbl_ev016A;
		CutsceneDataList[0x016B]->Textures = texTbl_ev016B;
		CutsceneDataList[0x016C]->Textures = texTbl_ev016C;
		CutsceneDataList[0x016D]->Textures = texTbl_ev016D;
		CutsceneDataList[0x016E]->Textures = texTbl_ev016E;
		CutsceneDataList[0x016F]->Textures = texTbl_ev016F;
		CutsceneDataList[0x0170]->Textures = texTbl_ev0170;
		CutsceneDataList[0x0171]->Textures = texTbl_ev0171;
		CutsceneDataList[0x0176]->Textures = texTbl_ev0176;
		CutsceneDataList[0x0177]->Textures = texTbl_ev0177;
		CutsceneDataList[0x0178]->Textures = texTbl_ev0178;
		CutsceneDataList[0x0179]->Textures = texTbl_ev0179;
		CutsceneDataList[0x017A]->Textures = texTbl_ev017A;
		CutsceneDataList[0x017B]->Textures = texTbl_ev017B;
		CutsceneDataList[0x017C]->Textures = texTbl_ev017C;*/
		//CutsceneDataList[0x0180]->Textures = texTbl_ev0180;

		//60 FPS faces
		//for (int i = 0; i < faceTable_Length; i++) faceTable[i].nbFrame = faceTable[i].nbFrame * 2;
	}
}