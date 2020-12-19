#include <dirent.h>
//#include "concat.c"
# define PATH "C:/Users/Utkarsh Verma/Desktop/Projects/"
void create_Dir()
{
    char new_path[100];

    concat(new_path,PATH,"Directories");
    mkdir(new_path);

    concat(new_path,new_path,"/Teachers");
    mkdir(new_path);

    concat(new_path,PATH,"Directories/Students");
    mkdir(new_path);

    concat(new_path,PATH,"Directories/Students/Class1");
    mkdir(new_path);

    concat(new_path,PATH,"Directories/Students/Class2");
    mkdir(new_path);

    concat(new_path,PATH,"Directories/Students/Class3");
    mkdir(new_path);

    concat(new_path,PATH,"Directories/Students/Class4");
    mkdir(new_path);

    concat(new_path,PATH,"Directories/Students/Class5");
    mkdir(new_path);
}

