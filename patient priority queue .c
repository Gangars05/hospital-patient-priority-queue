#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient
{
    char name[20];
    int priority;
};

struct Patient queue[MAX];
int count = 0;

/* Add a patient */
void addPatient(char name[], int priority)
{
    strcpy(queue[count].name, name);
    queue[count].priority = priority;
    count++;

    printf("Patient %s added with priority %d\n", name, priority);
}

/* Treat the highest-priority patient */
void treatNext()
{
    if (count == 0)
    {
        printf("No patients waiting.\n");
        return;
    }

    int pos = 0;

    for (int i = 1; i < count; i++)
    {
        if (queue[i].priority < queue[pos].priority)
        {
            pos = i;
        }
    }

    printf("Treating patient: %s (Priority %d)\n",
           queue[pos].name, queue[pos].priority);

    for (int i = pos; i < count - 1; i++)
    {
        queue[i] = queue[i + 1];
    }

    count--;
}

int main()
{
    /* Add P1-P6 as given in the challenge */
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\nTreatment Order:\n");

    treatNext();
    treatNext();
    treatNext();
    treatNext();
    treatNext();
    treatNext();

    printf("\nTesting new Emergency Patient:\n");

    addPatient("P1", 3);
    addPatient("P2", 2);
    addPatient("P3", 3);

    treatNext();

    addPatient("P7", 1);

    treatNext();
    treatNext();
    treatNext();

    return 0;
}
