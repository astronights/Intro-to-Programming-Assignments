//Name: AGRAWAL, Shubhankar
//UID: 3035345306
#include <iostream>
using namespace std;
int num = 0;
struct input //Structure that stores properties of all inputs.
{
	string type;
	string direction;
	int x;
	int y;
};
input enter[20];
struct position //Structure to store the positions of the sources and keep changing them as we move.
{
	int xco;
	int yco;
	string direction;
};
struct answers // Structure to print out the answers.
{
	int source;
	int dest;
};
answers solution[5];
string singlemirror(string mirror, string &beam);
string doublemirror(string mirror, string &beam);
int movefunc(int &m, int &n, string &dir);

int main ()
{
    int i, d = 0, snum, l = 0;;
    position sources[5], dests[5];
    bool check = true;
    char dummy = ',';
    //cout<<"Please enter the length and breadth of the maze: ";
    cin>>i;
    //cout<<"Please enter the number of items: ";
    cin>>num;
    for(int k = 0; k < num; k++)
    {
    	cin>>enter[k].type;
    	if(enter[k].type == "dest")
    	{
    		enter[k].direction = d+65;
    		cin>>enter[k].x>>dummy>>enter[k].y;	
    		dests[d].xco = enter[k].x;
    		dests[d].yco = enter[k].y;
    		d++;
    	}
    	else if (enter[k].type == "source")
    	{
    		snum++;
    		cin>>enter[k].direction;
    		cin>>enter[k].x>>dummy>>enter[k].y;	
    	}
    	else if(enter[k].type == "block")
    	{
    		enter[k].direction = " ";
    		cin>>enter[k].x>>dummy>>enter[k].y;
    	}
    	else
    	{
    		cin>>enter[k].direction;
    		cin>>enter[k].x>>dummy>>enter[k].y;	
    	}
    }
    /*checking code: for(int k = 0; k < num; k++)
    {
    	cout<<endl<<"Type of object: "<<enter[k].type<<"\t Direction: "<<enter[k].direction<<"\t x-coordinate: "<<enter[k].x<<"\t y-coordinate: "<<enter[k].y;
    }*/
    for(int a = 0; a < 5; a++)
    {
    	solution[a].dest = 0;
    }
    for(int k = 0; k < num; k++)
    {
    	if(enter[k].type == "source")
    	{
    		solution[l].source = l + 1;
    		sources[l].xco = enter[k].x;
    		sources[l].yco = enter[k].y;
    		sources[l].direction = enter[k].direction;

    			while(check == true)
    			{

    				sources[l].xco, sources[l].yco = movefunc(sources[l].xco, sources[l].yco, sources[l].direction);
    				if(sources[l].xco > i-1 || sources[l].yco > i-1 || sources[l].xco < 0 || sources[l].yco < 0)
    				{
    					solution[l].dest = 88;
    					check = false;
    				}
    				else if (sources[l].xco == enter[k].x && sources[l].yco == enter[k].y)
    				{
    					solution[l].dest = 88;
    					check = false;
    				}
    				for(int a = 0; a < d; a++)
    				{
    					if(sources[l].xco == dests[a].xco && sources[l].yco == dests[a].yco)
    					{
    						solution[l].dest = a + 1;
    						check = false;
    					}	
    				}
    				//checkingcode: cout<<'\t'<<sources[l].xco<<'\t'<<sources[l].yco;
    			}
    		cout<<solution[l].source<<" - ";
    		if(solution[l].dest == 88)
    		{
    			cout<<char(solution[l].dest)<<endl;
    		}
    		else
    		{
    			cout<<solution[l].dest<<endl;
    		}
    		l++;
    		
    	}
    	check = true;
    }
    return 0;
}
string singlemirror(string mirror, string &beam)
{
	if(mirror == "nw")
	{
		if(beam == "south")
		{
			beam = "west";
		}
		else if (beam == "east")
		{
			beam = "north";
		}
		else
		{
			beam = "0";
		}
	}
	else if(mirror == "ne")
	{
		if(beam == "south")
		{
			beam = "east";
		}
		else if (beam == "west")
		{
			beam = "north";
		}
		else
		{
			beam = "0";
		}
	}
	else if(mirror == "sw")
	{
		if(beam == "north")
		{
			beam = "west";
		}
		else if (beam == "east")
		{
			beam = "south";
		}
		else
		{
			beam = "0";
		}
	}
	else if(mirror == "se")
	{
		if(beam == "north")
		{
			beam = "east";
		}
		else if (beam == "west")
		{
			beam = "south";
		}
		else
		{
			beam = "0";
		}
	}
	return beam;
}
string doublemirror(string mirror, string &beam)
{
	if(mirror == "nw")
	{
		if(beam == "north")
		{
			beam = "east";
		}
		else if(beam == "south")
		{
			beam = "west";
		}
		else if(beam == "east")
		{
			beam = "north";
		}
		else if(beam == "west")
		{
			beam = "south";
		}
	}
	else if(mirror == "ne")
	{
		if(beam == "north")
		{
			beam = "west";
		}
		else if(beam == "south")
		{
			beam = "east";
		}
		else if(beam == "east")
		{
			beam = "south";
		}
		else if(beam == "west")
		{
			beam = "north";
		}
	}
	return beam;
}
int movefunc(int &m, int &n, string &dir) //Updates the position of the laser beam after moving.
{
	if(dir == "north")
	{
		n = n + 1;
	}
	else if(dir == "south")
	{
		n = n - 1;
	}
	else if(dir == "west")
	{
		m = m - 1;
	}
	else if(dir == "east")
	{
		m = m + 1;
	}
	else
	{
		m = n = -1;
	}
	for(int z = 0; z < num; z++)
	{
		if(m == enter[z].x & n == enter[z].y)
		{
			if(enter[z].type == "single")
			{
				dir = singlemirror(enter[z].direction, dir);
			}
			else if(enter[z].type == "double")
			{
				dir = doublemirror(enter[z].direction, dir);
			}
			else if(enter[z].type == "block" || enter[z].type == "source")
			{
				m = n = -1;
				dir = '0';
			}
		}
	}
	return m, n;
}