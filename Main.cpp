
// Dark GDK - The Game Creators - www.thegamecreators.com

// the wizard has created a very simple 2D project that uses Dark GDK
// it can be used as a starting point in making your own 2D games

// whenever using Dark GDK you must ensure you include the header file
#include "DarkGDK.h"
#include <vector>
#include <time.h>

using namespace std;

 vector<vector<int> > CreateMatrix(int, int, int);
 bool IsItIN(int, vector<int>);

// the main entry point for the application is this function
void DarkGDK ( void )
{

	// in this application a backdrop is loaded and then several
	// animated sprites are displayed on screen

	// when starting a Dark GDK program it is useful to set global
	// application properties, we begin by turning the sync rate on,
	// this means we control when the screen is updated, we also set
	// the maximum rate to 60 which means the maximum frame rate will
	// be set at 60 frames per second
	dbSyncOn   ( );
	dbSyncRate ( 60 );
	dbInk(0xFFFFFF, 0xFFFFFF);

	CreateMatrix(3,3,3);
	

	while ( LoopGDK ( ) )
	{
		dbSync ( );
	}
	return;
}

 vector<vector<int> > CreateMatrix(int n, int m, int MineNumber)
{
	int size=n*m;
	vector<vector<int> > Matrix;
	vector<int> MinePosition;
	
	MinePosition.resize(MineNumber);
	//memset(&MinePosition,0,sizeof(int)*MineNumber);
	for(int i=0; i<MineNumber; i++)
	{
		MinePosition[i]=0;
	}
		
	srand(time(NULL));
	for(int i=0; i<MineNumber; i++)
	{
		int TmpPosition;
		do
		{
			TmpPosition=(rand()%size);
		}while(IsItIN(TmpPosition, MinePosition));
		//	}while(0);
		MinePosition[i]=TmpPosition;
		
		
		char * Text=(char*)malloc(sizeof(char)*3);
		itoa(TmpPosition,Text,10);
		dbText(10+20*i, 10, Text);
		free(Text);
		

	}
	Matrix.resize(n);
	for(int i=0; i<n; i++)
	{
		Matrix[i].resize(m);
		for(int j=0; j<m; j++)
		{
			Matrix[i][j]=0;
		}

	}
 return Matrix;
}


  bool IsItIN(int Position, vector<int> MinePosition)
  {
	    int i=0;
		
		bool isitin=false;
		
		do
			{
				if(MinePosition[i]==Position) isitin=true;
				i++;

			}while(isitin == false && i<(int)MinePosition.size());
		return isitin;
  }
