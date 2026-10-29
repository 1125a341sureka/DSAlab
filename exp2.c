#include<stdio.h>
#include<stdlib.h>
#include<string.h >
struct Employee{
int id;
char name[50];
char designation[30];
float salary;
};
struct Employee *createRecords (int n) {
struct Employee *emp = (struct Employee *) malloc(n * sizeof(struct 
Employee));
    if (emp == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
    for (int i = 0; i < n; i++) {
printf("\nEnter detailsfor employee %d:\n",i+ 1);
printf("ID: ");
scanf("%d", &( emp + i)->id);
printf("Name: ");
scanf("%s", ( emp + i)->name);
printf("Designation: ");
scanf("%s", ( emp + i)->designation);
printf("Salary: ");
scanf("%f", &( emp + i)->salary);
}
    return emp;
}
void displayRecords (struct Employee *emp, int n) {
printf("\n%-6s %-15s %-15s %-10s\n", "ID", "Name", "Designation", 
"Salary");
    for (int i = 0; i < n; i++) {
printf("%-6d %-15s%-15s%-10.f\n",
               (
emp + i)->id, ( emp + i)->name, ( emp + i)->designation, ( emp + i)->salary);
}
}
struct Employee *searchById (struct Employee *emp, int n, int id){
    for (int i = 0; i < n; i++) {
        if ((
emp+i)->id== id)
            return (
emp+i);
}
return NULL;
}
int main(){
    int n, searchId;
    struct Employee *emp;
    printf("Enternumberofemployees:");
    scanf("%d",&n);
    emp = createRecords(n);
    displayRecords(emp,n);
    printf("\nEnteremployeeIDtosearch:");
    scanf("%d", & searchId);
    struct Employee *found = searchById(emp, n, searchId);
    if(found!=NULL)
        printf("Found: %d %s %s %.2f\n", found->id, found->name, found->designation, found->salary);
else
        printf("Employeenotfound.\n");
    free(emp);
return 0;
        }