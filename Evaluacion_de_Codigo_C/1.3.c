#include <stdio.h>

extern void f(int i);

void func(int expr)
{
    int i=4;    
    f(i);

    switch (expr)
    {
        /*4- DCL41-C. Do not declare variables inside a switch statement before the first case label*/
        //int i = 4;
        //f(i);
    case 0:
        i = 17;
    default:
        printf("%d\n", i);
    }
}

int main(void)
{
    func(0);
    //func(1);
    return 0;
}
    /*
    1- 
        Entraria en el switch en el caso 0, asignandole a la variable i el valor 17 y lo muestra porque entra en default dado que no hay break
    2-
        El problema yo lo encuentro en las lineas 13 y 14 debido a que tenemos
        la iniciacion de una variable y la llamada a una funcion dentro del switch sin ningun caso
        preestablecido por lo tanto este codigo seria inacesible.
    5- 
        rats:
            Entries in perl database: 33
            Entries in ruby database: 46
            Entries in python database: 62
            Entries in c database: 334
            Entries in php database: 55
            Total lines analyzed: 0
            Total time 0.000008 seconds
            0 lines per second
        cppchecker:
            Checking 1.3.c ...

        splint:
            Splint 3.1.2 --- 21 Feb 2021
            1.3.c: (in function func)
            1.3.c:15:10: Fall through case (no preceding break)
            Execution falls through from the previous case (use to mark
            fallthrough cases). (Use -casebreak to inhibit warning)
            1.3.c:17:13: Fall through case (no preceding break)
            1.3.c:13:19: Statement after switch is not a case: int i = 4
            The first statement after a switch is not a case. (Use -firstcase to inhibit
            warning)
            1.3.c:5:6: Function exported but not used outside 1.3: func
            A declaration is exported, but not used outside this module. Declaration can
            use static qualifier. (Use -exportlocal to inhibit warning)
            1.3.c:20:1: Definition of func

            Finished checking --- 4 code warnings


        vera++:
            1.3.c:1: no copyright notice found
            1.3.c:7: trailing whitespace
            1.3.c:28: trailing whitespace
            1.3.c:29: line is longer than 100 characters
            1.3.c:38: trailing empty line(s)
            1.3.c:38: too many consecutive empty lines
        
        valgrind:
            ==16788== Memcheck, a memory error detector
            ==16788== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
            ==16788== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
            ==16788== Command: ./a.out
            ==16788== 
            17
            ==16788== 
            ==16788== HEAP SUMMARY:
            ==16788==     in use at exit: 0 bytes in 0 blocks
            ==16788==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
            ==16788== 
            ==16788== All heap blocks were freed -- no leaks are possible
            ==16788== 
            ==16788== For lists of detected and suppressed errors, rerun with: -s
            ==16788== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

    */



