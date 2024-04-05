#pragma once
#ifndef __MAP_H__
#define __MAP_H__


#define MAP_CHIP_X_NUM	(20)	//マップチップ横の数
#define MAP_CHIP_Y_NUM	(10)	//マップチップ縦の数

//マップチップの1つのサイズ
const int MAP_CHIP_SIZE_X = (32);
const int MAP_CHIP_SIZE_Y = (32);


//マップチップ画像ファイルパス
#define MAP_CHIP_IMG_PATH_UP   "Data/Play/ダウンロードup.png"
#define MAP_CHIP_IMG_PATH_DOWN "Data/Play/ダウンロードdown.png"


extern int src_handle;
extern int src_handle2;


//マップチップの種類
enum MAP_CHIP_TYPE
{
	MP_CHIP_CLAY_PIPE_UP = 1,   //上にある土管
	MP_CHIP_CLAY_PIPE_DOWN,     //下にある土管
	MP_CHIP_CLAY_GROUND,        //地面
	MP_CHIP_CLAY_CEILING        //天井
};


//マップチップ構造体
struct  MapChip
{
	int handle;         //画像ハンドル
	int x, y;           //座標
	bool isDraw;        //描画フラグ
	MAP_CHIP_TYPE type; //種類
};


//マップチップ画像読み込み
void LoaMap();

//マップ初期化
void InitMap();

//マップ通常処理
void StepMap();

//マップ描画処理
void DrawMap();

//マップ後処理
void FinMap();

//マップチップデータ取得
MapChip* GetMapChip(int y_index);

#endif