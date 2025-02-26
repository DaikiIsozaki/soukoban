﻿// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<list>

enum Hexadecimal
{
	NON = 0x00,
	P	= 0x01,//Player
	B	= 0x02,//Box
	W	= 0x03,//Wall
	D	= 0x04,//Goal
	I	= 0x05,//ThirdWheel
	MAX
};

// TODO: ここでプリコンパイルするヘッダーを追加します

#endif //PCH_H
