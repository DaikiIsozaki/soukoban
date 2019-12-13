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
	MapCreate() {};
	~MapCreate() {};

	int FileLoad(int mapNo);


private:
	char filename[MAX_FILE_LENGTH];

};

