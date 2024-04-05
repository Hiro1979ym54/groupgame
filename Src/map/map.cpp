#include "DxLib.h"
#include <DxLib.h>
#include "map.h"


int src_handle = 0;
int src_handle2 = 0;

//マップチップ[縦の数][横の数]
MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };

//マップチップの配置データ
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

};

//マップチップ画像読み込み
void LoaMap()
{

	//失敗なら終了
	if (src_handle == -1)
		return;

	if (src_handle2 == -1)
		return;

	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//マップチップの種類によって、
			//画像のどの位置を切り取るか決める
			int start_x = 0;
			int start_y = 0;

			//上にある土管のマップチップ
			if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_UP)
			{
				//上にある土管の切り抜き開始位置を設定する
				start_x = 32;
				start_y = 32;
			}
			//下にある土管のマップチップ
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_DOWN)
			{
				//下にある土管の切り抜き開始位置を設定する
				start_x = 32;
				start_y = 32;
			}

			MapChip* map_chip = &mapChip[y_index][x_index];

			//元画像から各マップチップ画像のハンドルを作成(土管上)
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle);

			//元画像から各マップチップ画像のハンドルを作成(土管下)
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle2);

			//座標を決める
			map_chip->x = x_index * MAP_CHIP_SIZE_X;
			map_chip->y = y_index * MAP_CHIP_SIZE_Y;

			//描画フラグをON
			map_chip->isDraw = true;

			//タイプを記録
			map_chip->type = (MAP_CHIP_TYPE)mapChipData[y_index][x_index];

		}
	}

	//元画像を消去
	DeleteGraph(src_handle);
	DeleteGraph(src_handle2);

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
				int map_x = (int)(mapChip[y_index][x_index].x);
				int map_y = (int)(mapChip[y_index][x_index].y);
				DrawGraph(map_x, map_y, mapChip[y_index][x_index].handle, true);
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

//マップチップデータの取得
MapChip* GetMapChip(int y_index)
{
	return mapChip[y_index];
}