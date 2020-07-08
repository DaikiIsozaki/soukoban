int main()
{
	char** Mapinfo;
	int MapLengthX = 0;
	int MapLengthY = 0;
	bool Firstroad = true;
	std::list<unsigned char> container;

	char a[256];
	char filename[256];

	printf("変換させたいテキスト名:");
	scanf("%s",a);
	
	sprintf(filename, "Map/%s.txt", a);
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("読み込めません\n");
		return 0;
	}
	
	printf("読み込めたよ！\n");

	Mapinfo = new char*[600];
	for (int i = 0; i < 600; i++)
	{
		Mapinfo[i] = new char[1000];
	}

	for (int yy = 0; yy < 100; yy++)
	{
		fgets(Mapinfo[yy], 500, fp);

		if (Mapinfo[yy][0] == 'E')
		{
			Firstroad = false;
			break;
		}
		for (int xx = 0; xx < 100; xx++)
		{
			if (Firstroad)
			{
				if (Mapinfo[yy][xx] == 'A')
				{
					Firstroad = false;
					break;
				}
				MapLengthX++;
			}
			else
				break;
		}
		MapLengthY++;
	}

	for (int y = 0; y < 100; y++)
	{
		fgets(Mapinfo[y], 500, fp);

		if (Mapinfo[y][0] == 'E')
		{
			break;
		}

		for (int x = 0; x < 100; x++)
		{
			if (Mapinfo[y][x] == 'A')
			{
				break;
			}
			switch (Mapinfo[y][x])
			{
				//オブジェクト
			case 'W'://壁
				container.push_back((unsigned char)Hexadecimal::W);
				
				break;

			case 'P'://プレイヤー
				container.push_back((unsigned char)Hexadecimal::P);
				
				break;
				
			case 'B'://箱
				container.push_back((unsigned char)Hexadecimal::B);
			
				break;
				
			case '*'://目的地
				container.push_back((unsigned char)Hexadecimal::D);
				
				break;

			case 'I'://お邪魔虫
				container.push_back((unsigned char)Hexadecimal::I);

				break;
				
			case ' '://何もなし
				container.push_back((unsigned char)Hexadecimal::NON);
				break;
			}
		}
	}
	fclose(fp);

	sprintf(filename, "Map/%s.bin", a);
	fp = fopen(filename, "wb");

	unsigned char x = (unsigned char)MapLengthX;
	unsigned char y = (unsigned char)MapLengthY;

	fwrite(&x, sizeof(unsigned char), 1, fp);
	fwrite(&y, sizeof(unsigned char), 1, fp);

	for (auto obj : container)
	{
		fwrite(&obj, sizeof(unsigned char), 1, fp);
	}

	fclose(fp);
}


