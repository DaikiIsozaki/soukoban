#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

#define MAX_FILE_LENGTH	(20)

class MapCreate
{
public:
	MapCreate()=default;
	~MapCreate()=default;

	int FileLoad(int mapNo);


private:
	char filename[MAX_FILE_LENGTH];

};

