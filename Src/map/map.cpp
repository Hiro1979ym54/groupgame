#include "DxLib.h"
#include <DxLib.h>
#include "map.h"


int src_handle = 0;
int src_handle2 = 0;
int src_handle3 = 0;
int src_handle4 = 0;

MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];

//マップチップ画像読み込み
void LoadMap()
{

	//失敗なら終了
	if (src_handle == -1)
		return;

	if (src_handle2 == -1)
		return;

	if (src_handle3 == -1)
		return;

	if (src_handle4 == -1)
		return;


	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//マップチップの種類によって、
			//画像のどの位置を切り取るか決める
			int start_x = 0;
			int start_y = 0;
			
			//上にある土管(中)のマップチップ
			if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_UP)
			{

				//上にある土管(中)の切り抜き開始位置を設定する
				start_x = 0;
				start_y = 0;
				//元画像から各マップチップ画像のハンドルを作成(土管上)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_UP);

			}
			//下にある土管(中)のマップチップ
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_DOWN)
			{

				//下にある土管(中)の切り抜き開始位置を設定する
				start_x = 0;
				start_y = 0;
				//元画像から各マップチップ画像のハンドルを作成(土管下)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);

			}
			//上にある土管(大)のマップチップ
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_UP_2)
			{

				//上にある土管(大)の切り抜き開始位置を設定する
				start_x = 0;
				start_y = 0;
				//元画像から各マップチップ画像のハンドルを作成(土管上)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_UP);
				mapChip[y_index][x_index].x = x_index * MAP_CHIP_SIZE_X2;
				mapChip[y_index][x_index].y = y_index * MAP_CHIP_SIZE_Y2;
			}
			//下にある土管(大)のマップチップ
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_DOWN_2)
			{

				//上にある土管(大)の切り抜き開始位置を設定する
				start_x = 0;
				start_y = 0;
				//元画像から各マップチップ画像のハンドルを作成(土管上)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);
				mapChip[y_index][x_index].x = x_index * MAP_CHIP_SIZE_X2;
				mapChip[y_index][x_index].y = y_index * MAP_CHIP_SIZE_Y2;
			}
			MapChip* map_chip = &mapChip[y_index][x_index];

			//座標を決める
			mapChip[y_index][x_index].x = x_index * MAP_CHIP_SIZE_X;
			mapChip[y_index][x_index].y = y_index * MAP_CHIP_SIZE_Y;
			

			//描画フラグをON
			mapChip[y_index][x_index].isDraw = true;

			//タイプを記録
			mapChip[y_index][x_index].type = (MAP_CHIP_TYPE)mapChipData[y_index][x_index];

		}
	}

	//元画像を消去
	DeleteGraph(src_handle);
	DeleteGraph(src_handle2);
	DeleteGraph(src_handle3);
	DeleteGraph(src_handle4);
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
				DrawExtendGraph(map_x, map_y, map_x + MAP_CHIP_SIZE_X, map_y + MAP_CHIP_SIZE_Y, mapChip[y_index][x_index].handle, true);
				//DrawExtendGraph(map_x, map_y, map_x + MAP_CHIP_SIZE_X2, map_y + MAP_CHIP_SIZE_Y2, mapChip[y_index][x_index].handle, true);
			
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