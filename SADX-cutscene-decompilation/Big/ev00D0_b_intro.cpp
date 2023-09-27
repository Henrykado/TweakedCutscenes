#include "SADXModLoader.h"
#include "SADXEventFunctions.h"
#include "SADXEventVariables.h"

PVMEntry texTbl_ev00D0[] = {
	(char*)("SHAPE_FROG"), &texlist_shape_frog,
	(char*)("M_EM_YELLOW"), &M_EM_YELLOW_TEXLIST,
	(char*)("CHAOS0"), BOSSCHAOS0_TEXLISTS[0],
	(char*)("EV_CHAOS0_MANJU"), &EV_CHAOS0_MANJU_TEXLIST,
	(char*)("CHAOS_SURFACE"), &CHAOS_SURFACE_TEXLIST,
	0
};

void ev00D0_b_intro(int state)
{
	NJS_POINT3 pos = { 700.0f, 490.0f, -597.0f };
	NJS_POINT3 velo = { 0.0099999998f, -3.5999999f, -0.12f };
	switch (state) {
	case 1:
		player = EV_GetPlayer(0);
		emerald = 0;
		task_skywalk = 0;
		FROG = 0;
		BLACK = 0;
		EV_CameraOn();
		EV_PadOff();
		EV_CanselOn();
		EV_InitPlayer(0);
		SetBankDir(110);
		EventSe_Init(5);
		task_skywalk = CSkyWalk_create2(player, 131.0f);
		EV_SetPos(player, 1292.83f, 130.0f, -725.20001f);
		EV_SetAng(player, 0, 0xD300, 0);
		EV_InitPlayer(0);
		EV_CreateObjectFunc(&FROG, set_shapefrog,
			player->twp->pos.x,
			player->twp->pos.y + 12.0f,
			player->twp->pos.z,
			0, 0xD300, 0);
		EV_CameraAng(1, 0, 0x1700, 0x4300, 0);
		EV_CameraPos(1, 0, 1263.3199f, 316.32001f, -615.79999f);
		EV_Wait(20);
		EV_CameraPos(0, 100, 1273.976f, 245.89999f, -617.29999f);
		EV_CameraAng(0, 100, 0x1000, 0x4300, 0);
		EV_Wait(130);
		effect_create(0, 0, 700.0f, 490.0f, -597.0f, &ev_effect_list8);
		effect_scl(0, -9.5f, -9.5f);
		EV_Wait(8);
		effect_delete(0);
		EV_Wait(10);
		EvCreateKiran2(&pos, &velo, 0.60000002f, 1.0000001f);
		EV_Wait(29);
		chg_frogshape(2);
		EV_SetMode(FROG, 0);
		EV_SetPos(FROG, 1298.76f, 138.75f, -732.75f);
		EV_SetAng(FROG, 0xF500, 0x9500, -0x1000);
		EV_Wait(1);
		EV_ClrAction(player);
		EV_ClrAction(FROG);
		EV_SetAction(player, &action_b_b0030_big, &BIG_TEXLIST, 0.5f, 1, 0);
		EV_SetAction(FROG, &action_f_f0014_frog, &texlist_shape_frog, 1.0f, 1, 0);
		EventSe_Play(1, 1334, 1800);
		EventSe_Volume(1, -110, 1);
		EV_CameraAng(0, 105, 0x600, 0x4122, 0xEE);
		EV_CameraPos(0, 105, 1290.7f, 135.38f, -619.65997f);
		EV_Wait(1);
		EventSe_Volume(1, -40, 59);
		EV_Wait(59);
		EventSe_Volume(1, -70, 90);
		EV_Wait(40);
		effect_delete(0);
		EV_Wait(1);
		EV_CameraAng(0, 30, 0x1000, 0x4100, 0x100);
		EV_CameraPos(0, 30, 1290.1899f, 123.2757f, -619.75f);
		EV_CreateObject(&emerald, -550.33002f, 1.5f, 973.90002f, 0, 0, 0);
		EV_SetMode(emerald, 0);
		EV_Wait(40);
		EV_SetPos(emerald, 1290.84f, 126.57f, -685.46503f);
		EV_SetAng(emerald, 0x2000, 0, 0);
		EV_SetAction(emerald, &action_m_em_yellow, &M_EM_YELLOW_TEXLIST, 1.0f, 1, 0);
		EV_CameraAng(0, 0, 0x700, 0xF400, 0);
		EV_CameraPos(0, 0, 1240.687f, 132.05f, -693.63f);
		EV_Wait(4);
		EV_CameraPos(0, 150, 1275.525f, 132.05f, -683.07678f);
		EV_Wait(140);
		EV_CameraPos(0, 71, 1279.35f, 132.05f, -681.90002f);
		EV_Wait(66);
		RumbleA(0, 8);
		EV_SetAction(player, &action_b_b0031_big, &BIG_TEXLIST, 1.0f, 1, 1);
		EV_CameraAng(0, 3, 0x900, 0xF400, 0);
		EV_Wait(2);
		EventSe_Stop(1);
		EventSe_Oneshot(1338, 0, 0, 0);
		EV_CameraPos(0, 1, 1279.35f, 134.05f, -681.90002f);
		EV_CameraAng(0, 3, 0xFA00, 0xF400, 0);
		EV_Wait(2);
		EV_CameraAng(0, 3, 0x700, 0xF400, 0);
		EV_Wait(2);
		EV_CameraAng(0, 3, 0xFC00, 0xF500, 0);
		EV_Wait(2);
		EV_CameraPos(0, 1, 1279.35f, 130.05f, -681.90002f);
		EV_CameraAng(0, 3, 0x600, 0xF400, 0);
		EV_Wait(2);
		EV_CameraAng(0, 3, 0xFE00, 0xF400, 0);
		EV_Wait(2);
		EV_CameraPos(0, 1, 1279.35f, 132.05f, -681.90002f);
		EV_CameraAng(0, 3, 0x700, 0xF400, 0);
		EV_Wait(2);
		EV_CameraAng(0, 3, 0xFD00, 0xF400, 0);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0x600, 0xF300, 0);
		EV_Wait(3);
		EV_CameraAng(0, 4, 0xFF00, 0xF400, 0);
		EV_Wait(3);
		EV_CameraAng(0, 4, 0x500, 0xF400, 0);
		EV_Wait(3);
		EV_CameraAng(0, 4, 0xFF00, 0xF500, 0);
		EV_Wait(3);
		EV_CameraAng(0, 4, 0x400, 0xF400, 0);
		EV_Wait(3);
		EV_CameraAng(0, 4, 0, 0xF400, 0);
		EV_Wait(3);
		EV_SetAction(player, &action_b_b0030_big, &BIG_TEXLIST, 0.5f, 1, 6);
		EV_CameraAng(0, 4, 0x400, 0xF400, 0);
		EV_Wait(3);
		EV_CameraAng(0, 4, 0x200, 0xF400, 0);
		EV_Wait(10);
		EV_CameraPos(1, 190, 1280.3f, 132.28f, -685.79999f);
		EV_CameraPerspective(1, 190, 0x238E);
		EV_Wait(30);
		BGM_Play(MusicIDs_evtbgm04);
		moveObject(FROG, 1298.76f, 138.75f, -732.75f, 1298.4325f, 143.0f, -731.90002f, 6);
		EV_Wait(20);
		EV_SetAng(FROG, 0xF500, 0xC000, 0x1000);
		EV_Wait(25);
		EV_SetAng(FROG, 0xF500, 0x9500, 0);
		EV_Wait(18);
		EV_SetAction(FROG, &action_f_f0002_frog, &texlist_shape_frog, 1.1f, 1, 0);
		EV_Wait(15);
		EV_SetAng(FROG, 0xF500, 0xC400, 0x1000);
		EV_Wait(5);
		moveObject(FROG, 1298.4325f, 143.0f, -731.90002f, 1293.0f, 131.5f, -730.84003f, 5);
		EV_Wait(10);
		moveObject(FROG, 1293.0f, 131.5f, -730.84003f, 1257.0f, 130.0f, -728.79999f, 35);
		EV_Wait(35);
		moveObjectAngle2(FROG, 1257.0f, 130.0f, -728.79999f, 1236.7f, 120.0f, -712.5f, 0xF500, 0xC400, 0x1000, 0, 0x7C00, 0, 1);
		EV_SetAction(FROG, &action_f_f0002_frog, &texlist_shape_frog, 1.45f, 1, 0);
		EV_SetPos(player, 1292.83f, 131.0f, -725.20001f);
		EV_CameraPos(0, 0, 1147.6f, 100.8f, -697.20001f);
		EV_CameraAng(0, 0, 0x900, 0xCB00, 0);
		EV_CameraPerspective(1, 1, 0x3555);
		EV_Wait(1);
		EV_SetMode(FROG, 3);
		EV_SetColli(FROG, 1.0f);
		moveObject(FROG, 1236.7f, 120.0f, -712.5f, 1137.74f, 99.599998f, -707.97998f, 145);
		EV_Wait(101);
		CreateChaos0(1081.49f, 97.449997f, -711.29999f, 0, 0, 0, 1);
		EV_Wait(4);
		ToWaterChaos0();
		EV_CameraAng(0, 122, 0x300, 0x3300, 0xFE00);
		EV_CameraPos(0, 122, 1141.7f, 100.4f, -705.0f);
		EV_Wait(42);
		EV_SetAction(FROG, &action_f_f0001_frog, &texlist_shape_frog, 0.5f, 1, 0);
		EV_Wait(10);
		EV_SetMode(FROG, 0);
		EV_Wait(70);
		EV_CameraAng(0, 95, 0x300, 0x3500, 0xFE00);
		EV_CameraPos(0, 95, 1140.7531f, 100.4736f, -705.29999f);
		EV_CameraPerspective(1, 95, 0x3111);
		EV_Wait(64);
		EV_Wait(41);
		EV_SetAction(FROG, &action_f_f0001_frog, &texlist_shape_frog, 0.1f, 1, 0);
		MoveChaos0(1123.777f, 96.540001f, -708.57001f, 44);
		EventSe_Play(2, 1333, 1800);
		EventSe_Volume(2, -20, 1);
		EV_Wait(4);
		EV_CameraAng(0, 41, 0xF0C0, 0x3BA0, 0xFEE0);
		EV_CameraPos(0, 41, 1139.344f, 101.58f, -706.29999f);
		EV_Wait(40);
		EventSe_Stop(2);
		EV_SetPos(FROG, 1137.74f, 99.800003f, -707.97998f);
		DeleteChaos0();
		EV_CameraAng(0, 0, 0xF900, 0xC300, 0xFE00);
		EV_CameraPos(0, 0, 1080.9399f, 106.77f, -703.69f);
		EV_CameraPerspective(1, 45, 0x271C);
		EV_CameraPos(0, 50, 1134.9399f, 101.0f, -707.59998f);
		EV_CameraAng(0, 20, 0xFB00, 0xC300, 0x900);
		EV_Wait(20);
		EV_CameraAng(0, 25, 0xFB00, 0xC300, 0xFF00);
		EV_Wait(29);
		BGM_Stop();
		EV_SetPos(player, 1292.83f, 131.0f, -725.20001f);
		EV_LookPoint(player, 1265.0f, 142.0f, -714.5f);
		EV_CameraPerspective(1, 1, 0xB6);
		EV_Wait(1);
		chg_frogshape(7);
		EV_CameraAng(0, 0, 0x90F, 0xDCF9, 0);
		EV_CameraPos(0, 0, 1285.043f, 133.28f, -715.185f);
		EV_Wait(60);
		EV_SetAction(FROG, &action_f_f0001_frog, &texlist_shape_frog, 1.0f, 1, 0);
		EV_CameraAng(0, 160, 0x600, 0xDCF9, 0);
		EV_CameraPos(0, 160, 1274.067f, 135.10001f, -706.42999f);
		EV_CameraPerspective(1, 160, 0x31C7);
		EV_Wait(140);
		BGM_Play(MusicIDs_thebig);
		EV_CameraAng(0, 340, 0xC00, 57337, 0xFC00);
		EV_CameraPos(0, 340, 1281.04f, 136.57001f, -712.47803f);
		EV_SetAction(player, &action_b_b0001_big, &BIG_TEXLIST, 1.0f, 0, 0);
		EV_SetAction(player, &action_b_b0002_big, &BIG_TEXLIST, 1.0f, 1, 16);
		EV_Wait(380);
		EV_CameraAng(0, 80, 0x400, 0xE000, 0);
		EV_CameraPos(0, 80, 1283.78f, 141.67999f, -715.487f);
		EV_Wait(60);
		EV_SerifPlay(1315);
		EV_Msg(msgTbl_ev00D0[TextLanguage][0]); //"\aHuh... er... wha?"
		EV_CameraAng(0, 40, 0x400, 0xDF00, 0);
		EV_CameraPos(0, 40, 1284.5f, 141.778f, -716.17297f);
		EV_SetAction(player, &action_b_b0002_big, &BIG_TEXLIST, 0.80000001f, 1, 16);
		EV_MsgClose();
		EV_Wait(25);
		EV_SetPos(player, 1292.83f, 131.0f, -725.20001f);
		EV_SetAng(FROG, 0, 0xB000, 0);
		EV_CameraAng(0, 0, 0xF500, 0x4300, 0);
		EV_CameraPos(0, 0, 1302.9399f, 144.60001f, -725.79999f);
		EV_CameraAng(0, 160, 0xEC00, 0x4200, 0);
		EV_CameraPos(0, 160, 1303.6f, 144.60001f, -716.83002f);
		EV_SerifPlay(1316);
		EV_Msg(msgTbl_ev00D0[TextLanguage][1]); //"\aFroggy, is that you?"
		EV_Wait(1);
		EV_SerifWait();
		EV_Wait(10);
		EV_SerifPlay(1317);
		EV_Msg(msgTbl_ev00D0[TextLanguage][2]); //"\aYou're lookin' kinda \nweird, good bu"...
		EV_Wait(1);
		EV_SerifWait();
		EV_Wait(10);
		EV_MsgClose();
		EV_CameraAng(0, 230, 0xD00, 0x4600, 0);
		EV_CameraPos(0, 140, 1145.97f, 98.876999f, -707.01898f);
		EV_Wait(180);
		EV_SetAction(player, &action_b_b0028_big, &BIG_TEXLIST, 1.0f, 1, 20);
		EV_SetAction(FROG, &action_f_f0012_frog, &texlist_shape_frog, 1.0f, 0, 20);
		EV_Wait(32);
		EV_CameraPos(0, 85, 1145.84f, 98.876999f, -709.01501f);
		EV_Wait(25);
		EV_SetAng(FROG, 0, 0xA000, 0);
		EV_SetAction(FROG, &action_f_f0013_frog, &texlist_shape_frog, 1.0f, 1, 8);
		EV_Wait(63);
		moveObject(FROG, 1137.74f, 99.800003f, -707.97998f, 1153.1455f, 110.53f, -720.87402f, 15);
		EV_LookFree(player);
		if (task_skywalk)
		{
			FreeTask(task_skywalk);
			task_skywalk = 0;
		}
		EV_SetPos(player, 1262.02f, 121.0f, -711.53998f);
		EV_SetAng(player, 0, 0xBD00, 0);
		EV_Wait(15);
		EV_ClrAction(player);
		EV_ClrAction(FROG);
		EV_SetAction(FROG, &action_f_f0002_frog, &texlist_shape_frog, 1.6f, 1, 1);
		EV_CameraAng(0, 0, 0xB00, 0xB800, 0);
		EV_CameraPos(0, 0, 1251.25f, 134.0f, -713.85663f);
		EV_CameraAng(0, 80, 0x400, 0xB700, 0);
		EV_CameraPos(0, 80, 1234.3521f, 127.68f, -712.62f);
		EV_SetAng(FROG, 0x1200, 0x3A00, 0);
		EV_SetColli(FROG, 1.5f);
		EV_SetMode(FROG, 3);
		moveObject(FROG, 1229.8f, 112.0f, -702.82501f, 1287.5f, 127.56f, -685.79999f, 80);
		EV_SerifPlay(1318);
		EV_Msg(msgTbl_ev00D0[TextLanguage][3]); //"\aWhat's up with the tail?"
		EV_Wait(10);
		EV_SetAction(player, &action_b_b0011_big, &BIG_TEXLIST, 0.80000001f, 0, 8);
		EV_WaitAction(player);
		EV_CameraAng(0, 0, 0x700, 0x3A00, 0);
		EV_CameraPos(0, 0, 1293.52f, 127.11f, -687.95001f);
		EV_ClrAction(player);
		EV_SetAction(player, &action_b_b0028_big, &BIG_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(FROG, &action_f_f0001_frog, &texlist_shape_frog, 1.0f, 1, 1);
		EV_CameraAng(0, 90, 0xB00, 0x4700, 0xFD00);
		EV_CameraPos(0, 90, 1293.3766f, 127.1445f, -686.0f);
		EV_SerifWait();
		EV_MsgClose();
		EV_SetAction(FROG, &action_f_f0009_frog, &texlist_shape_frog, 1.7f, 0, 1);
		chg_frogshape(0);
		EV_CameraAng(0, 50, 0xE00, 0x4700, 0xFD00);
		EV_Wait(56);
		EV_CameraAng(0, 0, 0, 0x4000, 0);
		EV_CameraPos(0, 0, 1273.12f, 136.2337f, -711.75f);
		EV_FreeObject(&emerald);
		EV_CameraAng(0, 105, 0xD00, 0x3400, 0);
		EV_CameraPos(0, 105, 1277.12f, 131.7f, -707.48999f);
		EV_Wait(10);
		chg_frogshape(6);
		EV_SetAction(player, &action_b_b0029_big, &BIG_TEXLIST, 1.2f, 0, 4);
		EV_WaitAction(player);
		EV_CameraAng(0, 0, 0xEF00, 0xA100, 0);
		EV_CameraPos(0, 0, 1257.6f, 144.8876f, -715.48651f);
		EV_SetAction(player, &action_b_b0028_big, &BIG_TEXLIST, 1.0f, 1, 0);
		EV_SetMode(FROG, 0);
		EV_SetPos(player, 1266.3f, 120.4f, -707.24469f);
		EV_SetAng(player, 0, 0x2100, 0);
		EV_SetPos(FROG, 1287.1f, 129.0f, -685.79999f);
		EV_SetAng(FROG, 0, 0xAE00, 0);
		EV_CameraPerspective(1, 120, 0x29F5);
		EV_CameraPos(0, 120, 1259.9f, 142.5f, -713.27002f);
		EV_SerifPlay(1319);
		EV_Msg(msgTbl_ev00D0[TextLanguage][4]); //"\aHey, wait a minute!   \nYou swallowed"...
		EV_Wait(85);
		EV_SetAction(FROG, &action_f_f0002_frog, &texlist_shape_frog, 1.5f, 1, 8);
		EV_Wait(10);
		moveObject(FROG, 1287.1f, 129.0f, -685.79999f, 1276.16f, 122.44f, -691.94f, 10);
		EV_Wait(10);
		EV_SetAction(player, &action_b_b0027_big, &BIG_TEXLIST, 1.0f, 1, 0);
		EV_SetAng(player, 0, 0xD500, 0);
		moveObject(FROG, 1270.58f, 122.44f, -686.3667f, 1236.64f, 120.8f, -704.79999f, 70);
		EV_CameraPerspective(1, 1, 0x3111);
		EV_CameraAng(0, 0, 0x900, 0xC800, 0xFE00);
		EV_CameraPos(0, 0, 1249.0f, 121.6f, -688.95398f);
		EV_CameraTargetObj(1, 1, FROG, 0.0f, 5.0f, 0.0f, 0);
		EV_CameraPos(0, 63, 1230.62f, 121.9213f, -701.76001f);
		EV_MsgClose();
		EV_Wait(10);
		EV_SetAng(player, 0, 0xD400, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xD300, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xD200, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xD100, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xD000, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xCF00, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xCE00, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xCD00, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xCC00, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xCB00, 0);
		EV_Wait(1);
		EV_SetAng(player, 0, 0xCA00, 0);
		EV_Wait(30);
		EV_CameraTargetFree();
		EV_ClrAction(player);
		EV_SetAng(player, 0, 0xC500, 0);
		EV_SetAng(FROG, 0, 0xC100, 0);
		EV_CameraPos(1, 0, 1227.526f, 150.84399f, -682.36438f);
		EV_CameraAng(1, 0, 0xE844, 0xE80C, 256);
		moveObject(FROG, 1236.64f, 120.8f, -704.79999f, 1204.067f, 115.2f, -704.15997f, 60);
		EV_MovePoint(player, 1244.1899f, 122.3f, -706.03998f);
		EV_CameraPos(0, 250, 1220.78f, 145.7f, -682.79999f);
		EV_SerifPlay(1320);
		EV_Msg(msgTbl_ev00D0[TextLanguage][5]); //"\aCome back here... \nWhat's wrong with"...
		EV_Wait(1);
		EV_SerifPlay(1321);
		EV_Msg(msgTbl_ev00D0[TextLanguage][6]); //"\aSomething's not right. We've always "...
		EV_Wait(1);
		EV_SerifWait();
		EV_CameraPos(1, 0, 1235.9399f, 138.73f, -701.21997f);
		EV_CameraAng(1, 0, 0xF044, 0xD80C, 0xFC00);
		EV_CameraPos(1, 100, 1229.0f, 142.10001f, -696.57892f);
		EV_Wait(20);
		EV_SerifPlay(1322);
		EV_Msg(msgTbl_ev00D0[TextLanguage][7]); //"\aFroggy!   Wait up!    Oh, dear!"
		BLACK = COverlayCreate(0.01f, 0.001f, 0.0f, 0.0f, 0.0f);
		EV_Wait(15);
		EV_MovePoint(player, 1196.1899f, 117.3f, -708.90002f);
		EV_SerifWait();
		EV_MsgClose();
		EV_MoveFree(player);
		EV_SetPos(0, 1173.5f, 97.133003f, -703.57599f);
		EV_SetAng(0, 0x4BB, 0xC93A, 0xFFE7);
		break;
	case 2:
		EV_CameraOff();
		EV_PadOn();
		EV_SetPos(0, 1168.58f, 97.599998f, -710.59998f);
		EV_SetAng(0, 0, 0xB850, 0);
		chg_frogshape(7);
		stopObjectAll();
		effect_delete(0);
		EV_Wait(1);
		DeleteChaos0();
		if (task_skywalk)
		{
			FreeTask(task_skywalk);
			task_skywalk = 0;
		}
		if (BLACK)
		{
			FreeTask(BLACK);
			BLACK = 0;
		}
		EV_InitPlayer(0);
		EV_FreeObject(&FROG);
		EV_FreeObject(&emerald);
		EventSe_Close();
		break;
	}
}