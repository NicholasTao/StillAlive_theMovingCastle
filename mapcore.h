class MapCore{
public:
	MapCore();
	char mapdata[80][80];
};

MapCore::MapCore()
{
	for (int i = 1 ; i < 80 ; i++)
		for (int j = 1 ; j < 80 ; j++){
			mapdata[i][j] = (i+j)%10+48;
	}
}