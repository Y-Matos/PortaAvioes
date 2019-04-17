#ifndef AVIAO_H
#define AVIAO_H
#include <string>
using std::string;

class Aviao
{
public:
	Aviao();
	~Aviao();
	
	void initTiposDeAviao();
	void getTiposDeAviao() const;
	void setTiposDeAviao(int,string&);
	
private:
	
	const static int numDeTipos = 5;
	string tiposDeAviao[numDeTipos];
	
};

#endif // AVIAO_H
