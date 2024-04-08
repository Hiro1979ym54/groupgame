#pragma once
#ifndef __MAP_H__
#define __MAP_H__


#define MAP_CHIP_X_NUM	(100)	//マップチップ横の数
#define MAP_CHIP_Y_NUM	(3)	//マップチップ縦の数
#define DOKAN_WIDTH	(109)				//プレイヤーの横サイズ
#define DOKAN_HEIGHT (240)				//プレイヤーの縦サイズ

//マップチップの1つのサイズ
const int MAP_CHIP_SIZE_X = (109); //土管サイズ中
const int MAP_CHIP_SIZE_Y = (240);
const int MAP_CHIP_SIZE_X2 = (159); //土管サイズ大
const int MAP_CHIP_SIZE_Y2 = (290);


//マップチップ画像ファイルパス
#define MAP_CHIP_IMG_PATH_UP   "Data/Play/土管サイズ中(下).png"
#define MAP_CHIP_IMG_PATH_DOWN "Data/Play/土管サイズ中(上).png"

extern int src_handle;
extern int src_handle2;
extern int src_handle3;
extern int src_handle4;

//マップチップの種類
enum MAP_CHIP_TYPE
{
	MP_CHIP_CLAY_PIPE_UP = 1,   //上にある土管(中)
	MP_CHIP_CLAY_PIPE_DOWN,     //下にある土管(中)
	MP_CHIP_CLAY_PIPE_UP_2,     //上にある土管(大)
	MP_CHIP_CLAY_PIPE_DOWN_2,
	
};


//マップチップ構造体
struct  MapChip
{
	int handle;         //画像ハンドル
	int x, y;           //座標
	int Mapsize_W, Mapsize_H;	//土管の横、縦幅
	bool isDraw;        //描画フラグ
	MAP_CHIP_TYPE type; //種類
};


//マップチップ画像読み込み
void LoadMap();

//マップ初期化
void InitMap();

//マップ描画処理
void DrawMap();

//マップ後処理
void FinMap();

//マップチップデータ取得
MapChip* GetMapChip(int y_index);



//マップチップ[縦の数][横の数]
extern MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];

//マップチップの配置データ
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 2},
	                                     
};

#endif