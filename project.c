#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct job {
    int job_id;
    char job_title[50];
    char job_description[100];
    char job_requirements[100];
    char job_category[100];
};
struct candidate {
    int candidate_id;
    char candidate_name[50];
    char candidate_email[50];
    char candidate_phone[20];
};
void create_job(struct job j);
void update_job(int id, int g, char val);
void delete_job(int job_id);
void apply_job(int a, int b);
void update_candidate_details(struct candidate k);
int main() {
    FILE *fjb;
    fjb = fopen("jobs.txt", "r");
    if (fjb == NULL) {
    FILE *fjb;
    fjb = fopen("jobs.txt", "w");
        fclose(fjb);
    }
    FILE *hh;
    hh= fopen("candidate.txt","r");
    if (hh == NULL){
        fclose(hh);
        FILE *hh;
        hh = fopen("candidate.txt","w");
        fclose(hh);
    }
    FILE *hh1;
    hh1= fopen("applicant.txt","r");
    if (hh1 == NULL){
        fclose(hh1);
        FILE *hh1;
        hh1 = fopen("applicant.txt","w");
        fclose(hh);
    }
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Create job\n");
        printf("2. Update job\n");
        printf("3. Delete job\n");
        printf("4. Apply for job\n");
        printf("5. Add candidate details\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct job j;
                printf("Enter job ID: ");
                scanf("%d", &j.job_id);
                printf("Enter job title: ");
                scanf("%s", &j.job_title);
                printf("Enter job description: ");
                scanf("%s", &j.job_description);
                printf("Enter job category (1. IT, 2. Sales, 3. Marketing): ");
                scanf("%s", &j.job_category);
                printf("Enter job requirements: ");
                scanf("%s", &j.job_requirements);
                create_job(j);
                break;
            }
            case 2: {
                char val;
                int g, id;
                printf("Enter job ID: ");
                scanf("%s", &id);
                printf("Enter field to update ([1]title, [2]description, [3]category, [4]requirements): ");
                scanf("%s", &g);
                printf("Enter new value: ");
                scanf("%s", &val);
                update_job(id,g,val);
                break;
            }
            case 3: {
                int job_id;
                printf("Enter job ID to delete: ");
                scanf("%d", &job_id);
                delete_job(job_id);
                break;
            }
            case 4: {
                int candidate_id, job_id;
                printf("Enter candidate ID: ");
                scanf("%d", &candidate_id);
                printf("Enter job ID: ");
                scanf("%d", &job_id);
                apply_job(candidate_id, job_id);
                break;
            }
            case 5: {
                struct candidate l;
                printf("Enter candidate ID: ");
                scanf("%d", &l.candidate_id);
                printf("Enter name");
                scanf("%s", &l.candidate_name);
                printf("Enter email");
                scanf("%s", &l.candidate_email);
                printf("Enter phone no");
                scanf("%s", &l.candidate_phone);
                update_candidate_details(l);
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);
    return 0;
    return 0;
}
void create_job(struct job j) {
    FILE *fph;
    fph = fopen("jobs.txt", "a");
    fprintf(fph, "%d %s %s %s %s\n", j.job_id, j.job_title, j.job_description, j.job_requirements, j.job_category);
    fclose(fph);
    printf("Job created successfully!\n");
}
void update_job(int id, int g, char val) {
    FILE *fp;
    FILE *fp1;
    fp = fopen("jobs.txt", "r");
    if (feof(fp)) {
        printf("No such Job found\n");
        return;
    }else{
        int tmp;
        int cn=0;
        char aary[5000][5];
        int i=0;
        while(1){
            char ttle, dcs, req, ctg, id1;
            char sd[5];
            fscanf(fp,"%s %s %s %s %s",id1, ttle,dcs,req,ctg);
            if (id1 == id){cn=1; tmp=i;}
            aary[i][0] = id1;
            aary[i][1] = ttle;
            aary[i][2] = dcs;
            aary[i][3] = req;
            aary[i][4] = ctg;
            i++;
            if (feof(fp)){break;}
        }
        if(cn == 0){printf("id not found");}
        else{
            aary[tmp][g-1]=val;
        }
        fclose(fp);
        fp1 = fopen("jobs.txt", "w");
        for(int k=0;k<i;k++){
            fprintf(fp1,"%s %s %s %s %s",aary[k][0],aary[k][1],aary[k][2],aary[k][3],aary[k][4]);
        }
        fclose(fp1);
    }
return;
    }


void delete_job(int id) {
FILE *fp;
    FILE *fp1;
    fp = fopen("jobs.txt", "r");
    if (feof(fp)) {
        printf("No such Job found\n");
        return;
    }else{
        int tmp;
        int cn=0;
        char aary[5000][5];
        int i=0;
        while(1){
            char ttle, dcs, req, ctg, id1;
            char sd[5];
            fscanf(fp,"%s %s %s %s %s",id1, ttle,dcs,req,ctg);
            if (id1 == id){cn=1; tmp=i;}
            aary[i][0] = id1;
            aary[i][1] = ttle;
            aary[i][2] = dcs;
            aary[i][3] = req;
            aary[i][4] = ctg;
            i++;
            if (feof(fp)){break;}
        }
        if(cn == 0){printf("id not found");}
        else{
            for (int ia = tmp; ia < i; ia++) {
                for(int mm=0;mm<5;mm++){
                    char tmp = aary[ia][mm];
                    aary[ia][mm] = aary[ia+1][mm];
                    aary[ia+1][mm] = tmp;
                }
    }
        }
        fclose(fp);
        fp1 = fopen("jobs.txt", "w");
        for(int k=0;k<i-1;k++){
            fprintf(fp1,"%s %s %s %s %s",aary[k][1],aary[k][2],aary[k][3],aary[k][4],aary[k][5]);
        }
    }
return;
    }

void apply_job(int a, int b) {
    FILE *hh1;
    hh1 = fopen("applicant.txt","a");
    fprintf(hh1," %s %s",a,b);
    printf("Candidate applied for job successfully!\n");
    fclose(hh1);
}
void update_candidate_details(struct candidate k) {
    FILE *fpe;
    fpe = fopen("candidates.txt","a");
    fprintf(fpe,"%s %s %s %s\n",k.candidate_id,k.candidate_name,k.candidate_email,k.candidate_phone);
    printf("Candidate details updated successfully!\n");
    fclose(fpe);
}