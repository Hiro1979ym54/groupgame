#include "DxLib.h"
#include <DxLib.h>
#include "map.h"


int src_handle = 0;
int src_handle2 = 0;
int src_handle3 = 0;
int src_handle4 = 0;

MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];

//�}�b�v�`�b�v�摜�ǂݍ���
void LoadMap()
{

	//���s�Ȃ�I��
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
			//�}�b�v�`�b�v�̎�ނɂ���āA
			//�摜�̂ǂ̈ʒu��؂��邩���߂�
			int start_x = 0;
			int start_y = 0;
			
			//��ɂ���y��(��)�̃}�b�v�`�b�v
			if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_UP)
			{

				//��ɂ���y��(��)�̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 0;
				start_y = 0;
				//���摜����e�}�b�v�`�b�v�摜�̃n���h�����쐬(�y�Ǐ�)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_UP);

			}
			//���ɂ���y��(��)�̃}�b�v�`�b�v
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_DOWN)
			{

				//���ɂ���y��(��)�̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 0;
				start_y = 0;
				//���摜����e�}�b�v�`�b�v�摜�̃n���h�����쐬(�y�ǉ�)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);

			}
			//��ɂ���y��(��)�̃}�b�v�`�b�v
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_UP_2)
			{

				//��ɂ���y��(��)�̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 0;
				start_y = 0;
				//���摜����e�}�b�v�`�b�v�摜�̃n���h�����쐬(�y�Ǐ�)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_UP);
				mapChip[y_index][x_index].x = x_index * MAP_CHIP_SIZE_X2;
				mapChip[y_index][x_index].y = y_index * MAP_CHIP_SIZE_Y2;
			}
			//���ɂ���y��(��)�̃}�b�v�`�b�v
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_DOWN_2)
			{

				//��ɂ���y��(��)�̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 0;
				start_y = 0;
				//���摜����e�}�b�v�`�b�v�摜�̃n���h�����쐬(�y�Ǐ�)
				mapChip[y_index][x_index].handle = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);
				mapChip[y_index][x_index].x = x_index * MAP_CHIP_SIZE_X2;
				mapChip[y_index][x_index].y = y_index * MAP_CHIP_SIZE_Y2;
			}
			MapChip* map_chip = &mapChip[y_index][x_index];

			//���W�����߂�
			mapChip[y_index][x_index].x = x_index * MAP_CHIP_SIZE_X;
			mapChip[y_index][x_index].y = y_index * MAP_CHIP_SIZE_Y;
			

			//�`��t���O��ON
			mapChip[y_index][x_index].isDraw = true;

			//�^�C�v���L�^
			mapChip[y_index][x_index].type = (MAP_CHIP_TYPE)mapChipData[y_index][x_index];

		}
	}

	//���摜������
	DeleteGraph(src_handle);
	DeleteGraph(src_handle2);
	DeleteGraph(src_handle3);
	DeleteGraph(src_handle4);
}

//�}�b�v������
void InitMap()
{
	//�}�b�v�`�b�v��S��0�ŏ�����
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

//�}�b�v�`�揈��
void DrawMap()
{
	//�}�b�v�`�b�v��`��
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//�`��t���O��ON�̃`�b�v�̂�
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

//�}�b�v�㏈��
void FinMap()
{
	//���ׂẴ}�b�v�`�b�v�摜����������
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//����
			if (mapChip[y_index][x_index].handle != 0)
			{
				DeleteGraph(mapChip[y_index][x_index].handle);
			}
		}
	}

}

//�}�b�v�`�b�v�f�[�^�̎擾
MapChip* GetMapChip(int y_index)
{
	return mapChip[y_index];
}