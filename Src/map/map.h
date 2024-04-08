#pragma once
#ifndef __MAP_H__
#define __MAP_H__


#define MAP_CHIP_X_NUM	(100)	//�}�b�v�`�b�v���̐�
#define MAP_CHIP_Y_NUM	(3)	//�}�b�v�`�b�v�c�̐�
#define DOKAN_WIDTH	(109)				//�v���C���[�̉��T�C�Y
#define DOKAN_HEIGHT (240)				//�v���C���[�̏c�T�C�Y

//�}�b�v�`�b�v��1�̃T�C�Y
const int MAP_CHIP_SIZE_X = (109); //�y�ǃT�C�Y��
const int MAP_CHIP_SIZE_Y = (240);
const int MAP_CHIP_SIZE_X2 = (159); //�y�ǃT�C�Y��
const int MAP_CHIP_SIZE_Y2 = (290);


//�}�b�v�`�b�v�摜�t�@�C���p�X
#define MAP_CHIP_IMG_PATH_UP   "Data/Play/�y�ǃT�C�Y��(��).png"
#define MAP_CHIP_IMG_PATH_DOWN "Data/Play/�y�ǃT�C�Y��(��).png"

extern int src_handle;
extern int src_handle2;
extern int src_handle3;
extern int src_handle4;

//�}�b�v�`�b�v�̎��
enum MAP_CHIP_TYPE
{
	MP_CHIP_CLAY_PIPE_UP = 1,   //��ɂ���y��(��)
	MP_CHIP_CLAY_PIPE_DOWN,     //���ɂ���y��(��)
	MP_CHIP_CLAY_PIPE_UP_2,     //��ɂ���y��(��)
	MP_CHIP_CLAY_PIPE_DOWN_2,
	
};


//�}�b�v�`�b�v�\����
struct  MapChip
{
	int handle;         //�摜�n���h��
	int x, y;           //���W
	int Mapsize_W, Mapsize_H;	//�y�ǂ̉��A�c��
	bool isDraw;        //�`��t���O
	MAP_CHIP_TYPE type; //���
};


//�}�b�v�`�b�v�摜�ǂݍ���
void LoadMap();

//�}�b�v������
void InitMap();

//�}�b�v�`�揈��
void DrawMap();

//�}�b�v�㏈��
void FinMap();

//�}�b�v�`�b�v�f�[�^�擾
MapChip* GetMapChip(int y_index);



//�}�b�v�`�b�v[�c�̐�][���̐�]
extern MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];

//�}�b�v�`�b�v�̔z�u�f�[�^
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 2},
	                                     
};

#endif