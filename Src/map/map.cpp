#include "DxLib.h"
#include <DxLib.h>
#include "map.h"



#define MAP_CHIP_X_NUM	(12)	//マップチップ横の数
#define MAP_CHIP_Y_NUM	(10)	//マップチップ縦の数


//マップチップ画像ファイルパス
#define MAP_CHIP_IMG_PATH "Data/Play/Dokan.png"


//マップチップの種類
enum MAP_CHIP_TYPE
{
	MP_CHIP_CLAY_PIPE_TIP,  //土管先端
	MP_CHIP_CLAY_PIPE_ROOT, //土管根本

};


//マップチップ構造体
struct  MapChip
{
	int handle;  //画像ハンドル
	int x, y;    //座標
	bool isDraw; //描画フラグ
};


//マップチップ[縦の数][横の数]
MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };


//マップチップの配置データ
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},

};


//マップチップの1つのサイズ
const int MAP_CHIP_SIZE_X = (32);
const int MAP_CHIP_SIZE_Y = (64);


//マップチップ画像読み込み
void LoaMap()
{
	//元画像を読み込み
	int src_handle = LoadGraph(MAP_CHIP_IMG_PATH);

	//失敗なら終了
	if (src_handle == -1)
		return;

	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//マップチップの種類によって、
			//画像のどの位置を切り取るか決める
			int start_x = 0;
			int start_y = 0;

			//土管先端のマップチップ
			if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_TIP)
			{
				//土管先端の切り抜き開始位置を設定する
				start_x = 0;
				start_y = 0;
			}
			//土管根本
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_ROOT)
			{
				//土管根本の切り抜き開始位置を設定する
				start_x = 0;
				start_y = 0;
			}

			MapChip* map_chip = &mapChip[y_index][x_index];

			//元画像から各マップチップ画像のハンドルを作成
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle);

			//座標を決める
			map_chip->x = x_index * MAP_CHIP_SIZE_X;
			map_chip->y = y_index * MAP_CHIP_SIZE_Y;

			//描画フラグをON
			map_chip->isDraw = true;

		}
	}

	//元画像を消去
	DeleteGraph(src_handle);

}

//マップ初期化
void InitMap()
{
	//マップチップを全て0で初期化
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			mapChip[y_index][x_index].handle = 0;
			mapChip[y_index][x_index].x = 0;
			mapChip[y_index][x_index].y = 0;
			mapChip[y_index][x_index].isDraw = false;
		}
	}
}

//マップ通常処理
void StepMap()
{

}

//マップ描画処理
void DrawMap()
{
	//マップチップを描画
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//描画フラグがONのチップのみ
			if (mapChip[y_index][x_index].isDraw)
			{

			}
		}
	}
}

//マップ後処理
void FinMap()
{
	//すべてのマップチップ画像を消去する
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//消去
			if (mapChip[y_index][x_index].handle != 0)
			{
				DeleteGraph(mapChip[y_index][x_index].handle);
			}
		}
	}

}