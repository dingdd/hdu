#include <Single>

Data* Data::sig=NULL;

int Data::get()const{
	return i;
}

void Data::set(int i){
	this->i=i;
}

Data* Data::instance(){
	if(sig!=NULL)
		return sig;
	sig=new Data();
	return sig;
}

