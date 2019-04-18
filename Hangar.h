#ifndef HANGAR_H
#define HANGAR_H
#include <string>
using std::string;

class Hangar
{
public:
	Hangar();
	~Hangar();
	
	void initTiposDeAviao();
	void getTiposDeAviao() const;
	void setTiposDeAviao(int,string&);
	
    void info() const;
    
private:
	
	const static int numDeTipos = 5;
	string tiposDeAviao[numDeTipos];
	
};

#endif // HANGAR_H
