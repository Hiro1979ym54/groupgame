
#include <DxLib.h>
#include "Effect.h"
#include "Common.h"

/*
  進める手順
  1：エフェクト情報構造体を完成させる
  2：InitEffect関数を実装する
  3：LoadEffect関数を実装する
  4：PlayEffect関数を実装する
  5：DrawEffect関数を実装する　←ここまで実装できれば消えないエフェクトが完成する
  6：StepEffect関数を実装する
  7：FinEffect関数を実装する

  ★完成後は自分のゲームにソースファイルをコピーしエフェクトを実装してみましょう!!
*/

//一度に表示できるエフェクト最大数
#define EFFECT_MAX_NUM		(20)

//エフェクトのアニメ最大数
#define EFFECT_ANIME_MAX_NUM	(4)	

//エフェクト情報
struct EffectInfo
{
	EFFECT_TYPE effectType;								//エフェクトの種類

	int handle[EFFECT_ANIME_MAX_NUM];					//画像ハンドル

	int x, y;											//座標
	bool isUse;											//使用フラグ

	int animeNum;										//アニメ数
	int currentAnimeIndex;								//現在のアニメ番号

	float changeTime;									//１枚あたりの表示時間
	float currentAnimeTime;								//現在のアニメ時間
};

//エフェクト情報
EffectInfo effectInfo[EFFECT_MAX_NUM];

//エフェクトのファイルパス
const char effectFilePath[EFFECT_TYPE_NUM][256] =
{
	"Data/Effect/EffectExplosion.png",
	"Data/Effect/EffectRecovery.png",
};

//各エフェクトのアニメ数
const int effectAnimeImgNum[EFFECT_TYPE_NUM] =
{
	4,	//EFFECT_TYPE_EXPLOSION
	3,	//EFFECT_TYPE_RECOVERY
};

//各エフェクトの画像分割数 [0] = x, [1] = y
const int effectImageSplitNum[EFFECT_TYPE_NUM][2] =
{
	{ 2, 2,},	//EFFECT_TYPE_EXPLOSION
	{ 2, 2,},	//EFFECT_TYPE_RECOVERY
};

//エフェクトの画像サイズ
const int effectImageSize[EFFECT_TYPE_NUM] =
{
	64,	//EFFECT_TYPE_EXPLOSION
	32,	//EFFECT_TYPE_RECOVERY
};

//各エフェクトのアニメ画像切り替え時間
const float effectChageTime[EFFECT_TYPE_NUM] =
{
	0.05f,	//EFFECT_TYPE_EXPLOSION
	0.1f,	//EFFECT_TYPE_RECOVERY
};

//エフェクトの読み込み
//引数	：エフェクトの種類、作成数
void LoadEffect(EFFECT_TYPE type, int create_num)
{
	//エフェクトの作成分for文を回す
	for (int createNum_index = 0; createNum_index < create_num; createNum_index++)
	{
		//エフェクトの情報構造体配列分for文を回す
		for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
		{
			//読み込みしていないエフェクト情報を見つける
			//（ひとつ目の画像ハンドルがゼロなら読み込みされてない）
			if (effectInfo[effect_index].handle[0] == 0)
			{

				int animeImagenum = effectAnimeImgNum[type];

				int ImageSplitNumX = effectImageSplitNum[type][0];
				int ImageSplitNumY = effectImageSplitNum[type][1];

				int ImageSize = effectImageSize[type];

				//画像を分割読み込み
				int success_flg = LoadDivGraph(effectFilePath[type], animeImagenum, ImageSplitNumX, ImageSplitNumY, ImageSize, ImageSize, effectInfo[effect_index].handle);

				//成功した
				if (success_flg == 0)
				{
					//アニメ数を格納
					effectInfo[effect_index].animeNum = animeImagenum;

					//1枚当たりの表示時間を設定
					effectInfo[effect_index].changeTime = effectChageTime[type];

					//エフェクトの種類を設定
					effectInfo[effect_index].effectType = type;
				}

				//成否にかかわらず抜ける
				break;
			}
		}
	}

}

//エフェクトの初期化
void InitEffect()
{
	//すべてのエフェクト情報の変数をクリアする（ゼロにする）
	for (int index = 0; index < EFFECT_MAX_NUM; index++) {
		effectInfo[index].x = 0;
		effectInfo[index].y = 0;
		effectInfo[index].isUse = false;
		effectInfo[index].animeNum = 0;
		effectInfo[index].currentAnimeIndex = 0;
		effectInfo[index].changeTime = 0.0f;
		effectInfo[index].currentAnimeTime = 0.0f;
		for (int maxnum_index = 0; maxnum_index < EFFECT_ANIME_MAX_NUM; maxnum_index++) {
			effectInfo[index].handle[maxnum_index] = 0;
		}
	}
}

//エフェクト通常処理
void StepEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//使用中ならアニメ時間を経過させて、アニメ番号を更新する
		if (effectInfo[effect_index].isUse == true)
		{
			//時間更新
			effectInfo[effect_index].currentAnimeTime += 1.0f / FRAME_RATE;

			//画像切り替わるに必要な時間経過したら
			if (effectInfo[effect_index].currentAnimeTime >= effectInfo[effect_index].changeTime)
			{
				//次の画像へ
				effectInfo[effect_index].currentAnimeIndex++;

				//計測時間リセット
				effectInfo[effect_index].currentAnimeTime = 0.0f;

				//次の画像がもし無いなら
				if (effectInfo[effect_index].currentAnimeIndex >= EFFECT_ANIME_MAX_NUM)
				{
					//使用中フラグをOFFに
					effectInfo[effect_index].isUse = false;

					//以下の処理は不要
					break;
				}

			}


		}
	}
}

//エフェクト描画処理
void DrawEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//使用中なら現在のアニメ番号で描画する
		if (effectInfo[effect_index].isUse)
		{
			DrawRotaGraph(effectInfo[effect_index].x, effectInfo[effect_index].y, 1.0f, 0.0f,
				effectInfo[effect_index].handle[effectInfo[effect_index].currentAnimeIndex], true);
		}
	}
}

//エフェクトの後処理
void FinEffect()
{
	//すべてのエフェクトを削除する
	for (int effct_index = 0; effct_index < EFFECT_ANIME_MAX_NUM; effct_index++)
	{
		//すべて削除する
		for (int index = 0; index < EFFECT_MAX_NUM; index++)
		{
			//★ゼロ以外なら削除する


			//画像削除引数を設定する
			DeleteGraph(effectInfo[index].handle[index]);

			//★削除したらゼロを入れておく
			effectInfo[index].currentAnimeIndex = 0;
		}

	}
}

//エフェクトの再生
//引数	：エフェクトの種類, Ｘ座標, Ｙ座標, １枚あたりの表示時間
void PlayEffect(EFFECT_TYPE type, int x, int y)
{
	//未使用エフェクトを探して再生
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//使用中なら以下行わない
		if (!effectInfo[effect_index].isUse)
		{
			//タイプが一致した
			if (effectInfo[effect_index].effectType == type)
			{
				//座標設定
				effectInfo[effect_index].x = x;
				effectInfo[effect_index].y = y;

				//計測用の変数をクリア
				effectInfo[effect_index].currentAnimeIndex = 0;
				effectInfo[effect_index].currentAnimeTime = 0.0f;

				//使用中にする
				effectInfo[effect_index].isUse = true;

				//抜ける
				break;
			}
		}
	}
}
