#include "SADXModLoader.h"
#include "SADXEventFunctions.h"
#include "SADXEventVariables.h"

PVMEntry texTbl_ev0061[] = {
	(char*)("VER1_WING"), &VER1_WING_TEXLIST,
	(char*)("VER2_WING"), &VER2_WING_TEXLIST,
	(char*)("VER3_WING"), &texlist_ver3_wing,
	0
};

void ev0061_a_intro2(int state)
{
	switch (state) {
	case 1:
		player = EV_GetPlayer(0);
		obj_ver2_wing = 0;
		EV_CanselOn();
		EV_Wait(1);
		EV_CameraOn();
		EV_PadOff();
		EV_InitPlayer(0);
		SetBankDir(94);
		EventSe_Init(5);
		seqVars[1] = 0;
		EV_SetPos(player, 134.0f, 0.0f, 675.0f);
		EV_SetAng(player, 0, 0x8000, 0);
		EV_InitPlayer(0);
		EV_SetAction(player, &action_a_a0110_amy, &AMY_TEXLIST, 1.0f, 1, 16);
		EV_LookFree(player);
		EV_ClrFace(player);
		EV_SetFace(player, "A");
		EventSe_Play(0, 1333, 1800);
		obj_ver2_wing = SetEventBirdie0();
		EV_SetPos(obj_ver2_wing, -100.0f, 5.5f, -5.5f);
		EV_SetAng(obj_ver2_wing, 0, 0, 0);
		EV_SetMode(obj_ver2_wing, 0);
		EV_CreatePlayer(6, EggrobForEvent0, 384.70001f, 5.0f, 412.0f, 0, 0x8000, 0);
		EV_InitPlayer(6);
		BGM_Play(MusicIDs_evtbgm01);
		EV_Wait(1);
		EV_SetPos(player, 134.0f, 0.0f, 675.0f);
		EV_SetAng(player, 0, 0x8000, 0);
		EV_CameraTargetFree();
		EV_CameraPos(1, 0, 134.0f, 34.799999f, 654.776f);
		EV_CameraAng(1, 0, 0xD800, 0x8000, 0);
		EV_SerifPlay(845);
		if (VoiceLanguage == Languages_English)
			EV_SetFace(player, "C");
		if (VoiceLanguage == Languages_Japanese)
			EV_SetFace(player, "FEF");
		EV_Msg(msgTbl_ev0061[TextLanguage][0]); //"\aEggman?   Can it be?"
		EV_Wait(1);
		EV_SerifWait();
		if (VoiceLanguage == Languages_English)
			EV_Wait(15);
		EventSe_Oneshot(1334, 0, 0, 0);
		EV_Wait(15);
		EV_LookPoint(player, 132.8f, 5.5f, 662.0f);
		EV_SetAction(player, &action_a_a0110_amy, &AMY_TEXLIST, 0.30000001f, 1, 1);
		EV_Wait(10);
		EV_ClrFace(player);
		if (VoiceLanguage == Languages_Japanese)
			EV_SetFace(player, "AEBB");
		EV_Wait(3);
		if (VoiceLanguage == Languages_English)
			EV_SetFace(player, "F");
		EV_SerifPlay(846);
		EV_Msg(msgTbl_ev0061[TextLanguage][1]); //"\aWhat's that?"
		EV_Wait(17);
		EV_MsgClose();
		EventSe_Stop(0);
		EV_LookPoint(player, 134.0f, 5.5f, 631.75f);
		EventSe_Play(1, 1334, 1800);
		EV_CameraPath(&cpathtag_e0061cam_22, 0.89999998f);
		EV_CameraPerspective(1, 100, 0x11C7);
		EV_Wait(24);
		EV_LookFree(player);
		EV_ClrFace(player);
		EV_Wait(50);
		EV_SetFace(player, "JJJ");
		EV_Wait(30);
		EV_ClrAction(player);
		EV_LookFree(player);
		EV_LookPoint(player, 134.0f, 8.8470001f, 670.64001f);
		EV_CameraPos(0, 3, 134.0f, 8.8470001f, 670.64001f);
		EV_CameraAng(0, 3, 0xF1DB, 0x8000, 0);
		EV_Wait(11);
		efWhiteOn2(2, 65, 45);
		EventSe_Stop(1);
		EventSe_Oneshot(1339, 0, 0, 0);
		EV_SerifPlay(847);
		EV_Msg(msgTbl_ev0061[TextLanguage][2]); //"\aAhhh!   Watch it, watch it!"
		EV_ClrFace(player);
		EV_SetFace(player, "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV");
		EV_Wait(21);
		EV_SetPos(player, 128.0f, 0.0f, 693.09998f);
		EV_MsgClose();
		EV_SetPos(obj_ver2_wing, 128.0f, 0.0f, 693.09998f);
		EV_SetAng(obj_ver2_wing, 0, 0x8000, 0);
		EV_ClrAction(obj_ver2_wing);
		EV_CameraPerspective(1, 1, 0x271C);
		EV_Wait(6);
		EV_ClrAction(player);
		EV_SetAction(player, &action_a_a0111_amy, &AMY_TEXLIST, 0.69999999f, 0, 8);
		EV_SetAction(obj_ver2_wing, &action_w_w0123_wing, &VER2_WING_TEXLIST, 1.0f, 1, 0);
		EV_CameraPos(0, 0, 130.0f, 2.74f, 673.13f);
		EV_CameraAng(0, 0, 0xFF00, 0x7F00, 0);
		EV_SetFace(player, "X");
		EV_Wait(30);
		EV_SetAction(player, &action_a_a0112_amy, &AMY_TEXLIST, 0.80000001f, 0, 0);
		EV_SetFace(player, "FF");
		EV_Wait(7);
		EV_SerifPlay(848);
		EV_Msg(msgTbl_ev0061[TextLanguage][3]); //"\aOw!  You should watch \nwhere you're "...
		EV_SetAction(player, &action_a_a0113_amy, &AMY_TEXLIST, 0.80000001f, 1, 0);
		EV_Wait(6);
		EV_CameraPos(0, 70, 142.5f, 7.6799998f, 679.242f);
		EV_CameraAng(0, 70, 0xF400, 0x6200, 0x500);
		EV_Wait(80);
		EV_ClrFace(player);
		if (VoiceLanguage == Languages_Japanese)
		{
			EV_SetFace(player, "BDC");
		}
		if (VoiceLanguage == Languages_English)
		{
			EV_SetFace(player, "BDCD");
		}
		EV_Wait(1);
		EV_SerifPlay(849);
		EV_Msg(msgTbl_ev0061[TextLanguage][4]); //"\aHey.  Are you alright? \nYou look kin"...
		EV_Wait(80);
		EV_MsgClose();
		RumbleA(0, 5);
		EV_CameraAng(0, 4, 0xF500, 0x6200, 0x500);
		zero = EV_GetPlayer(6);
		EV_SetPos(zero, 127.475f, 12.0f, 850.0f);
		EV_SetAng(zero, 0, 0x7D00, 0);
		EV_Wait(2);
		EV_LookPoint(player, 127.0f, 13.0f, 680.09998f);
		EV_SetFace(player, "HHHHHHHHH");
		EV_CameraAng(0, 4, 0, 0x6200, 0x500);
		EventSe_Oneshot(1337, 0, 0, 0);
		BGM_Stop();
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF500, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xFE00, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF400, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xFF00, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF500, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF100, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF500, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF000, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF400, 0x6200, 0x500);
		EV_Wait(2);
		EV_CameraAng(0, 4, 0xF100, 0x6200, 0x500);
		EV_Wait(15);
		EV_CameraPos(0, 0, 133.38f, 3.0699999f, 683.35999f);
		EV_CameraAng(0, 0, 0xFE00, 0x7600, 0);
		EV_ClrFace(player);
		EV_Wait(5);
		EV_LookFree(player);
		EV_SetAction(player, &action_a_a0123_amy, &AMY_TEXLIST, 1.0f, 0, 0);
		EV_WaitAction(player);
		EV_CameraPos(0, 0, 128.8f, 9.6999998f, 839.85602f);
		EV_CameraAng(0, 0, 0x1B00, 0x7800, 0);
		EV_CameraPos(0, 70, 131.10001f, 0.37799999f, 825.34998f);
		EV_Wait(70);
		BGM_Play(MusicIDs_eggrobo);
		EV_Wait(25);
		moveObject(zero, 127.475f, 12.0f, 850.0f, 130.0f, 12.0f, 770.0f, 30);
		EV_SetAng(player, 0, 0xEE00, 0);
		EV_SetAng(obj_ver2_wing, 0, 0xEE00, 0);
		EV_ClrAction(player);
		EV_ClrAction(obj_ver2_wing);
		EV_SetAction(player, &action_a_a0124_amy, &AMY_TEXLIST, 1.0f, 1, 8);
		EV_SetAction(obj_ver2_wing, &action_w_w0124_wing, &VER2_WING_TEXLIST, 1.0f, 1, 8);
		EV_LookFree(player);
		EV_LookObject(player, zero, 0.0f, -2.0f, 0.0f);
		EV_Wait(15);
		EV_CameraPos(0, 0, 126.8f, 5.5f, 701.5f);
		EV_CameraAng(0, 0, 0x600, 0xF100, 0);
		EV_CameraPos(0, 60, 125.0f, 5.5f, 700.79999f);
		EV_CameraAng(0, 60, 0x600, 0xF100, 0);
		EV_ClrFace(player);
		EV_SetFace(player, "ABBEB");
		EV_Wait(20);
		EV_SerifPlay(850);
		EV_MsgW(0, msgTbl_ev0061[TextLanguage][5]); //"\aWhat's this?"
		EV_SetPos(zero, 127.475f, 12.0f, 850.0f);
		EV_SetAng(zero, 0, 0x7D00, 0);
		EV_Wait(10);
		EV_MsgClose();
		EV_CameraPos(0, 0, 128.83f, 12.3f, 666.85999f);
		EV_CameraAng(0, 0, 0x100, 0x7E00, 0);
		EV_CameraPos(0, 70, 128.83f, 2.1600001f, 668.0f);
		EV_CameraAng(0, 70, 0xB00, 0x7E00, 0);
		moveObject(zero, 127.475f, 12.0f, 850.0f, 134.0f, 12.0f, 550.0f, 170);
		EV_Wait(10);
		EV_SetAction(player, &action_a_a0126_amy, &AMY_TEXLIST, 1.9f, 0, 12);
		EV_SetAction(obj_ver2_wing, &action_w_w0126_wing, &VER2_WING_TEXLIST, 1.9f, 0, 12);
		EV_Wait(15);
		moveObject(player, 128.0f, 0.0f, 693.09998f, 128.0f, 0.0f, 688.0f, 17);
		moveObjectOn(obj_ver2_wing, 0.0f, 0.0f, 0.0f, 17, player);
		EV_Wait(5);
		EV_SetAction(player, &action_a_a0124_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0124_wing, &VER2_WING_TEXLIST, 1.0f, 1, 0);
		EV_Wait(5);
		throughplayer_on(player);
		throughplayer_on(zero);
		EV_Wait(25);
		EV_ClrFace(player);
		EV_SetFace(player, "M");
		EV_ClrAction(obj_ver2_wing);
		EV_ClrAction(player);
		EV_SetAction(player, &action_a_a0125_amy, &AMY_TEXLIST, 0.69999999f, 0, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0125_wing, &VER2_WING_TEXLIST, 0.69999999f, 0, 0);
		EV_Wait(10);
		EV_SerifPlay(851);
		EV_Msg(msgTbl_ev0061[TextLanguage][6]); //"\aHuh...  Uh oh."
		EV_CameraPos(1, 10, 122.847f, 2.1600001f, 667.59998f);
		EV_CameraAng(1, 10, 0xB00, 0x7700, 0);
		EV_Wait(9);
		EV_CameraPos(1, 20, 119.9f, 2.1600001f, 667.0f);
		EV_MsgClose();
		EV_WaitAction(player);
		EV_CameraPos(0, 0, 123.07f, 2.95f, 709.0f);
		EV_CameraAng(0, 0, 0x500, 0x500, 0x100);
		EV_LookFree(player);
		EV_SetPos(obj_ver2_wing, 120.0f, 0.0f, 693.09998f);
		EV_SetPos(player, 120.0f, 0.0f, 693.09998f);
		EV_SetAng(player, 0, 0x7600, 0);
		EV_SetAng(obj_ver2_wing, 0, 0x7600, 0);
		EV_SetAction(player, &action_a_a0124_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0124_wing, &VER2_WING_TEXLIST, 1.0f, 1, 0);
		EV_Wait(40);
		throughplayer_off(player);
		throughplayer_off(zero);
		EV_MovePoint(zero, 121.0f, 12.0f, 584.0f);
		EV_Wait(40);
		EV_CameraPos(0, 125, 123.057f, 2.9456999f, 712.52002f);
		EV_CameraAng(0, 125, 0x500, 0x500, 0x100);
		EV_SetAction(player, &action_a_a0126_amy, &AMY_TEXLIST, 1.1f, 1, 12);
		EV_SetAction(obj_ver2_wing, &action_w_w0126_wing, &VER2_WING_TEXLIST, 1.1f, 1, 12);
		moveObject(player, 120.0f, 0.0f, 693.09998f, 119.0f, 0.0f, 700.40002f, 95);
		moveObjectOn(obj_ver2_wing, 0.0f, 0.0f, 0.0f, 95, player);
		EV_Wait(96);
		EV_LookFree(player);
		EV_ClrAction(player);
		EV_ClrAction(obj_ver2_wing);
		EV_SetAction(player, &action_a_a0127_amy, &AMY_TEXLIST, 1.8f, 1, 4);
		EV_SetAction(obj_ver2_wing, &action_w_w0127_wing, &VER2_WING_TEXLIST, 1.8f, 1, 4);
		EV_Wait(4);
		EV_CameraChase(player);
		EV_SetAng(player, 0, 0, 0);
		EV_SetAng(obj_ver2_wing, 0, 0, 0);
		moveObject(player, 119.59f, 0.0f, 696.40002f, 118.8f, 0.0f, 765.0f, 92);
		moveObjectOn(obj_ver2_wing, 0.0f, 0.0f, 0.0f, 92, player);
		EV_MovePoint2(zero, 121.0f, 0.0f, 700.0f, 0.6f, 0.6f);
		EV_Wait(5);
		EV_ClrFace(player);
		EV_SetFace(player, "CI");
		EV_SerifPlay(852); 
		EV_Msg(msgTbl_ev0061[TextLanguage][7]); //"\aYikes!  \nYou almost ran me over, cre"...
		EV_Wait(10);
		EV_LookObject(player, zero, 0.0f, 8.0f, 0.0f);
		EV_Wait(14);
		EV_LookFree(player);
		EV_Wait(2);
		EV_MsgClose();
		EV_Msg(msgTbl_ev0061[TextLanguage][8]); //"\aOh no!  Let's get out of here!"
		//EV_SetPos(obj_ver2_wing, 118.8f, 0.0f, 728.79999f);
		//EV_SetPos(player, 118.8f, 0.0f, 728.79999f);
		EV_MovePoint2(player, 118.8f, 0.0f, 768.0f, 1.0, 0.5);
		moveObjectOn(obj_ver2_wing, 0.0f, 0.0f, 0.0f, 40, player);
		EV_CameraChaseFree();
		EV_CameraPos(0, 0, 181.73f, 16.700001f, 769.47498f);
		EV_CameraAng(0, 0, 0xFF00, 0x4000, 0);
		EV_WaitMove(player);
		EV_Wait(1);
		EV_SetAng(obj_ver2_wing, 0, -0x3500, 0);
		EV_MovePoint2(player, 72.150002f, 0.0f, 770.59998f, 1.3f, 2.0f); // enter
		moveObjectOn(obj_ver2_wing, 0.0f, 0.0f, 0.0f, 140, player);
		EV_Wait(5);
		EV_CameraChaseFree();
		EV_CameraPos(0, 0, 181.73f, 16.700001f, 769.47498f);
		EV_CameraAng(0, 0, 0xFF00, 0x4000, 0);
		//EV_Wait(20);
		EV_WaitMove(player);
		EV_SetAng(obj_ver2_wing, 0, 0x8A00, 0);
		EV_MovePoint2(player, 73.0f, 0.0f, 752.70001f, 1.0f, 1.5f);
		moveObjectOn(obj_ver2_wing, 0.0f, 0.0f, 0.0f, 45, player);
		EV_Wait(20);
		EV_MsgClose();
		EV_Wait(55);
		EV_SetPos(zero, 125.0f, 20.0f, 700.09998f);
		EV_Wait(5);
		EV_MovePoint(zero, 125.0f, 20.0f, 730.0f);
		EV_SetPos(obj_ver2_wing, 80.0f, 1.0f, 763.0f);
		EV_SetPos(player, 80.0f, 1.0f, 763.0f);
		EV_SetAng(player, 0, -0x4000, 0);
		EV_SetAng(obj_ver2_wing, 0, -0x4000, 0);
		EV_SetAction(player, &action_a_a0128_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0128_wing, &VER2_WING_TEXLIST, 1.0f, 1, 0);
		EV_CameraPos(0, 0, 43.077499f, 26.030001f, 759.58002f);
		EV_CameraAng(0, 0, 0xF400, 0xCF00, 0);
		EV_CameraPerspective(1, 1, 0x3111);
		EV_CameraPos(0, 0, 70.024002f, 12.24f, 737.29999f);
		EV_CameraAng(0, 0, 0x500, 0xC000, 0);
		EV_Wait(30);
		EV_MovePoint(zero, 115.0f, 20.0f, 740.09998f);
		EV_Wait(70);
		EV_MovePoint2(zero, 125.0f, 0.0f, 900.0f, 0.40000001f, 0.40000001f);
		EV_CameraPos(0, 50, 71.556f, 5.9000001f, 762.65997f);
		EV_Wait(50);
		EV_CameraPos(0, 70, 70.300003f, 8.2600002f, 758.22998f);
		EV_CameraAng(0, 70, 0xFF00, 0xA700, 0);
		EV_Wait(110);
		BGM_Stop();
		EV_RemovePlayer(6);
		EV_Wait(20);
		EV_LookPoint(player, 83.269997f, 5.3499999f, 752.146f);
		EV_ClrFace(player);
		EV_SetFace(player, "EC");
		EV_SerifPlay(853);
		EV_MsgW(60, msgTbl_ev0061[TextLanguage][9]); //"\aThat was one of Eggman's robots, huh?"
		EV_Wait(40);
		EV_SetAction(player, &action_a_a0129_amy, &AMY_TEXLIST, 1.0f, 0, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0129_wing, &VER2_WING_TEXLIST, 1.0f, 0, 0);
		EV_LookFree(player);
		EV_CameraPos(0, 180, 70.669998f, 4.21f, 755.92999f);
		EV_CameraAng(0, 180, 0x200, 0xA300, 0);
		EV_ClrFace(player);
		EV_SetFace(player, "DEC");
		EV_SerifPlay(854);
		EV_Msg(msgTbl_ev0061[TextLanguage][10]); //"\aHe must have captured you,\nand someh"...
		EV_SetAction(player, &action_a_a0131_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0131_wing, &VER2_WING_TEXLIST, 1.0f, 1, 0);
		EV_Wait(120);
		EV_ClrFace(player);
		EV_SetFace(player, "PDP");
		EV_SerifPlay(855);
		EV_MsgW(60, msgTbl_ev0061[TextLanguage][11]); //"\aDon't worry, I'll protect you!"
		EV_MsgClose();
		EV_CameraPos(0, 0, 132.5f, 3.53f, 751.79999f);
		EV_CameraAng(0, 0, 0xB00, 0x6700, 0);
		EV_SetPos(obj_ver2_wing, 88.0f, 0.5f, 768.0f);
		EV_SetPos(player, 88.0f, 0.5f, 768.0f);
		EV_SetAng(player, 0, 0x4000, 0);
		EV_SetAng(obj_ver2_wing, 0, 0x4000, 0);
		EV_ClrAction(player);
		EV_ClrAction(obj_ver2_wing);
		EV_SetAction(player, &action_a_a0121_amy, &AMY_TEXLIST, 0.89999998f, 1, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0121ver3_wing, &texlist_ver3_wing, 0.89999998f, 1, 0);
		EV_MovePoint2(player, 130.0f, 0.5f, 768.0f, 0.23f, 1.5f);
		moveObjectOn(obj_ver2_wing, 0.0f, 0.0f, 0.0f, 185, player);
		EV_Wait(20);
		EV_CameraPos(0, 140, 136.66f, 4.5f, 765.5f);
		EV_CameraAng(0, 140, 0xB00, 0x5000, 0);
		EV_Wait(60);
		EV_ClrFace(player);
		EV_SetFace(player, "CEGbbbbbbbbb");
		EV_SerifPlay(856);
		EV_Msg(msgTbl_ev0061[TextLanguage][12]); //"\aI'll do my best to keep us both from "...
		EV_WaitMove(player);
		EV_SetAction(player, &action_a_a0121_amy, &AMY_TEXLIST, 0.1f, 1, 0);
		EV_SetAction(obj_ver2_wing, &action_w_w0121ver3_wing, &texlist_ver3_wing, 0.1f, 1, 0);
		EV_SerifWait();
		EV_CameraPos(0, 0, 121.15f, 4.9499998f, 761.0f);
		EV_CameraAng(0, 0, 0xB00, 0xB100, 0);
		EV_CameraPos(0, 60, 120.1f, 4.9499998f, 768.0f);
		EV_Wait(40);
		EV_CameraPos(0, 0, 166.14999f, 15.95f, 743.79999f);
		EV_CameraAng(0, 0, 0xFB00, 0x5A00, 0);
		EV_Wait(1);
		break;
	case 2:
		EV_SetPos(player, 130.0f, 0.5f, 768.0f);
		EV_SetAng(player, 0, 0x4000, 0);
		EV_CameraOff();
		EV_PadOn();
		stopObjectAll();
		EV_InitPlayer(0);
		EV_RemovePlayer(6);
		EV_FreeObject(&obj_ver2_wing);
		throughplayer_off(player);
		efWhiteOff();
		seqVars[1] = 1;
		EventSe_Close();
		break;
	}
}