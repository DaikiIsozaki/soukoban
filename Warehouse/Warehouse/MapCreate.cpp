//|*******|//
//|include|//
//|*******|//
#include"Object.h"
#include "HitMove.h"
#include "ObjectManager.h"
#include "MapCreate.h"
#include"main.h"

int MapCreate::FileLoad(int mapNo)
{
	sprintf(m_filename,"Map/Map%d.bin",mapNo);
	FILE* fp = fopen(m_filename,"rb");
	if (fp == NULL)
		return -1;

	char mapinfo[2500];

	int maplengthX = fgetc(fp);
	int maplengthY = fgetc(fp);

	int sizeX = (SCREEN_X - maplengthX * OBJ_SIZE) / 2;
	int sizeY = (SCREEN_Y - maplengthY * OBJ_SIZE) / 2;

	fgets(mapinfo, SCREEN_X*SCREEN_Y, fp);

	for (int i = 0; i < maplengthX*maplengthY; i++)
	{
		switch (mapinfo[i])
		{
			//オブジェクト
		case WALL://壁
			ObjectManager::Get_Instance()->AddObj(WALL,  (i%maplengthX), (i / maplengthX), sizeX, sizeY);
			break;

		case PLAYER://プレイヤー
			ObjectManager::Get_Instance()->AddObj(PLAYER, (i% maplengthX), (i/maplengthX), sizeX, sizeY);
			break;

		case BOX://箱
			ObjectManager::Get_Instance()->AddObj(BOX, (i % maplengthX), (i/maplengthX), sizeX, sizeY);
			break;

		case DESTINATION://目的地
			ObjectManager::Get_Instance()->AddObj(DESTINATION, (i % maplengthX), (i/maplengthX), sizeX, sizeY);
			break;

		case THIRDWHEEL://お邪魔虫
			ObjectManager::Get_Instance()->AddObj(THIRDWHEEL, (i % maplengthX), (i / maplengthX), sizeX, sizeY);
			break;

		case NON://何もなし
			break;
		}
	}
	fclose(fp);

	return 0;

	//テキスト読み込み
	//Mapinfo = new char*[SCREEN_Y];
	//for (int i = 0; i < SCREEN_Y; i++)
	//{
	//	Mapinfo[i] = new char[SCREEN_X];
	//}
	//if (_Firstroad)
	//{
	//	
	//	for (int yy = 0; yy < 100; yy++)
	//	{
	//		fgets(Mapinfo[yy], 500, fp);
	//		if (Mapinfo[yy][0] == 'E')
	//		{
	//			_Firstroad = false;
	//			break;
	//		}
	//		for (int xx = 0; xx < 100; xx++)
	//		{
	//			if (_Firstroad)
	//			{
	//				if (Mapinfo[yy][xx] == 'A')
	//				{
	//					_Firstroad = false;
	//					break;
	//				}
	//				MapLengthX++;
	//			}
	//			else
	//				break;
	//		}
	//		MapLengthY++;
	//	}
	//}
	//for (int y = 0; y < 100; y++)
	//{
	//	fgets(Mapinfo[y], 500, fp);
	//	if (Mapinfo[y][0] == 'E')
	//	{
	//		break;
	//	}
	//	for (int x = 0; x < 100; x++)
	//	{
	//		
	//		if (Mapinfo[y][x] == 'A')
	//		{
	//			break;
	//		}
	//		int sizeX = (SCREEN_X - MapLengthX * OBJ_SIZE) / 2;
	//		int sizeY = (SCREEN_Y - MapLengthY * OBJ_SIZE) / 2;
	//		switch (Mapinfo[y][x])
	//		{
	//			//オブジェクト
	//		case 'W'://壁
	//			ObjectManager::Get_Instance()->AddObj(WALL,x,y,sizeX,sizeY);
	//			break;
	//		case 'P'://プレイヤー
	//			ObjectManager::Get_Instance()->AddObj(PLAYER, x, y, sizeX, sizeY);
	//			break;
	//		case 'B'://箱
	//			ObjectManager::Get_Instance()->AddObj(BOX, x, y, sizeX, sizeY);
	//			break;
	//		case '*'://目的地
	//			ObjectManager::Get_Instance()->AddObj(DESTINATION, x, y, sizeX, sizeY);
	//			break;
	//		case ' '://何もなし
	//			break;
	//		}
	//		
	//		
	//	}
	//}
	//for (int i = 0; i < SCREEN_Y; i++)
	//{
	//	delete[] Mapinfo[i];
	//}
	//delete[] Mapinfo;
	//Mapinfo = nullptr;
	//_Firstroad = true;
}

