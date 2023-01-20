/*
  Ejemplo de regla de concurrencia.
  Autor: Fernando Fernández Iglesias
 
  Regla: CON31-C. Do not destroy a mutex while it is locked
 
  Esta regla se refiere a una práctica de programación insegura en la que se destruye un objeto mutex
  (también conocido como un semáforo) mientras sigue siendo bloqueado. Esto puede causar problemas en el programa,
  Es importante asegurarse de que un mutex se ha desbloqueado antes de destruirlo para evitar errores en el programa.




    //EJEMPLO ERRÓNEO

    Este ejemplo de código es erroneo dado crea varios hilos que invocan la funcion do_work(), pasando un número único como ID. La función do_work()
    inicializa mutex si el argumento es 0 y destruye el mutex si el argumento es max_threads - 1. En todos los demás casos, la función do_work() proporciona un procesamiento normal.
    Cada hilo, excepto el hilo de limpieza final que incrementa el atomic_int completed cuando finaliza.

    #include <stdatomic.h>
    #include <stddef.h>
    #include <threads.h>

    mtx_t lock;

    atomic_int completed = ATOMIC_VAR_INIT(0);
    enum { max_threads = 5 };

    int do_work(void *arg) {
    int *i = (int *)arg;

    if (*i == 0) {
        if (thrd_success != mtx_init(&lock, mtx_plain)) {
            Handle error
        }
        atomic_store(&completed, 1);
    } else if (*i < max_threads - 1) {
        if (thrd_success != mtx_lock(&lock)) {
            Handle error
        }

        atomic_fetch_add(&completed, 1);
        if (thrd_success != mtx_unlock(&lock)) {
        Handle error
        }
    } else {
        mtx_destroy(&lock);
    }
    return 0;
    }

    int main(void) {
    thrd_t threads[max_threads];

    for (size_t i = 0; i < max_threads; i++) {
        if (thrd_success != thrd_create(&threads[i], do_work, &i)) {
            Handle error
        }
    }
    for (size_t i = 0; i < max_threads; i++) {
        if (thrd_success != thrd_join(threads[i], 0)) {
            Handle error
        }
    }
    return 0;
    }

*/

// Esta solución compatible elimina las condiciones de carrera al inicializar el mutex en el main()
// antes de crear los hilos y destruyendo los mutex después de unir los hilos.
#include <stdatomic.h>
#include <stddef.h>
#include <threads.h>

mtx_t lock;
/* Atomic so multiple threads can increment safely */
atomic_int completed = ATOMIC_VAR_INIT(0);
enum
{
    max_threads = 5
};

int do_work(void *dummy)
{
    if (thrd_success != mtx_lock(&lock))
    {
        /* Handle error */
    }
    /* Access data protected by the lock */
    atomic_fetch_add(&completed, 1);
    if (thrd_success != mtx_unlock(&lock))
    {
        /* Handle error */
    }

    return 0;
}

int main(void)
{
    thrd_t threads[max_threads];

    if (thrd_success != mtx_init(&lock, mtx_plain))
    {
        /* Handle error */
    }
    for (size_t i = 0; i < max_threads; i++)
    {
        if (thrd_success != thrd_create(&threads[i], do_work, NULL))
        {
            /* Handle error */
        }
    }
    for (size_t i = 0; i < max_threads; i++)
    {
        if (thrd_success != thrd_join(threads[i], 0))
        {
            /* Handle error */
        }
    }

    mtx_destroy(&lock);
    return 0;
}