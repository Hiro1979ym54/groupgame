#pragma once
#ifndef __MAP_H__
#define __MAP_H__


#define MAP_CHIP_X_NUM	(20)	//�}�b�v�`�b�v���̐�
#define MAP_CHIP_Y_NUM	(10)	//�}�b�v�`�b�v�c�̐�

//�}�b�v�`�b�v��1�̃T�C�Y
const int MAP_CHIP_SIZE_X = (32);
const int MAP_CHIP_SIZE_Y = (32);


//�}�b�v�`�b�v�摜�t�@�C���p�X
#define MAP_CHIP_IMG_PATH_UP   "Data/Play/�_�E�����[�hup.png"
#define MAP_CHIP_IMG_PATH_DOWN "Data/Play/�_�E�����[�hdown.png"


extern int src_handle;
extern int src_handle2;


//�}�b�v�`�b�v�̎��
enum MAP_CHIP_TYPE
{
	MP_CHIP_CLAY_PIPE_UP = 1,   //��ɂ���y��
	MP_CHIP_CLAY_PIPE_DOWN,     //���ɂ���y��
	MP_CHIP_CLAY_GROUND,        //�n��
	MP_CHIP_CLAY_CEILING        //�V��
};


//�}�b�v�`�b�v�\����
struct  MapChip
{
	int handle;         //�摜�n���h��
	int x, y;           //���W
	bool isDraw;        //�`��t���O
	MAP_CHIP_TYPE type; //���
};


//�}�b�v�`�b�v�摜�ǂݍ���
void LoaMap();

//�}�b�v������
void InitMap();

//�}�b�v�ʏ폈��
void StepMap();

//�}�b�v�`�揈��
void DrawMap();

//�}�b�v�㏈��
void FinMap();

//�}�b�v�`�b�v�f�[�^�擾
MapChip* GetMapChip(int y_index);

#endif