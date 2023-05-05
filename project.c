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
void update_job(int id, int g, char val[50]);
void delete_job(int job_id);
void apply_job(int a, int b);
void update_candidate_details(struct candidate k);
void view_job();
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
        printf("6. View Jobs\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct job j;
                printf("Enter job ID: ");
                scanf("%d", &j.job_id);
                printf("Enter job title: ");
                scanf("%s", &j.job_title);
                getchar();
                printf("Enter job description: ");
                scanf("%[^\n]s", j.job_description);
                printf("Enter job category (1. IT, 2. Sales, 3. Marketing): ");
                scanf("%s", &j.job_category);
                printf("Enter job requirements: ");
                scanf("%s", &j.job_requirements);
                create_job(j);
                break;
            }
            case 2: {
                char val[50];
                int g, id;
                printf("Enter job ID: ");
                scanf("%d", &id);
                printf("Enter field to update ([1]title, [2]description, [3]category, [4]requirements): ");
                scanf("%d", &g);
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
            case 6:{
                view_job();
                break;
            }
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 7);
    return 0;
}
void create_job(struct job j) {
    FILE *fph;
    fph = fopen("jobs.txt", "a");
    fprintf(fph, "%d\n%s\n%s\n%s\n%s\n", j.job_id, j.job_title, j.job_description, j.job_requirements, j.job_category);
    fclose(fph);
    printf("Job created successfully!\n");
}
void update_job(int id, int g, char val[50]) {
    FILE *fp;
    FILE *fp1;
    fp = fopen("jobs.txt", "r");
    if (0) {
        printf("No such Job found\n");
        return;
    }else{
        char ll[1];
        int tmp,idtmp;
        int cn=0;
        char aary[5000][4];
        int i=0;
        char  id1[100];
        char ttle[100][100], dcs[100][100], req[100][100], ctg[100][100];
        while(1){
            fgets(id1 + i,100,fp);
            fgets(ttle + i,100,fp);
            fgets(dcs + i,100,fp);
            fgets(req + i,100,fp);
            fgets(ctg + i,100,fp);
            ll[0] = id1[i];
            int tmp = atoi(ll);
            if (id == tmp){cn=1;idtmp = i;}
            i++;
            if (feof(fp)){break;}
        }
        if(cn == 0){printf("id not found\n");return;}
        fclose(fp);
        fp = fopen("jobs.txt", "w");
        for(int k=0;k<i-1;k++){
            if (k == idtmp && cn){
                fprintf(fp,"%c\n",id1[k]);
                if (g == 1){
                    fprintf(fp,"%s\n%s%s%s",val,dcs[k],req[k],ctg[k]);
                }
                else if(g == 2){
                    fprintf(fp,"%s%s\n%s%s",ttle[k],val,req[k],ctg[k]);
                }
                else if(g == 3){
                    fprintf(fp,"%s%s%s%s\n",ttle[k],dcs[k],req[k],val);
                }else{
                    fprintf(fp,"%s%s%s\n%s",ttle[k],dcs[k],val,ctg[k]);
                }
                continue;
            }
            fprintf(fp,"%c\n",id1[k]);
            fprintf(fp,"%s%s%s%s",ttle[k],dcs[k],req[k],ctg[k]);
            }
        }fclose(fp);
        return;
}
void delete_job(int id) {
    FILE *fp;
    FILE *fp1;
    fp = fopen("jobs.txt", "r");
    if (0) {
        printf("No such Job found\n");
        return;
    }else{
        char ll[1];
        int tmp,idtmp;
        int cn=0;
        char aary[5000][4];
        int i=0;
        char  id1[100];
        char ttle[100][100], dcs[100][100], req[100][100], ctg[100][100];
        while(1){
            fgets(id1 + i,100,fp);
            fgets(ttle + i,100,fp);
            fgets(dcs + i,100,fp);
            fgets(req + i,100,fp);
            fgets(ctg + i,100,fp);
            ll[0] = id1[i];
            int tmp = atoi(ll);
            if (id == tmp){cn=1;idtmp = i;}
            i++;
            if (feof(fp)){break;}
        }
        if(cn == 0){printf("id not found\n");return;}
        fclose(fp);
        fp = fopen("jobs.txt", "w");
        for(int k=0;k<i-1;k++){
            if (k == idtmp && cn){continue;}
            fprintf(fp,"%c\n",id1[k]);
            fprintf(fp,"%s%s%s%s",ttle[k],dcs[k],req[k],ctg[k]);
            }
        }fclose(fp);
        return;
    }

void apply_job(int a, int b) {
    FILE *hh1;
    hh1 = fopen("applicant.txt","a");
    fprintf(hh1," %d %d",a,b);
    printf("Candidate applied for job successfully!\n");
    fclose(hh1);
}
void update_candidate_details(struct candidate k) {
    FILE *fpe;
    fpe = fopen("candidate.txt","a");
    fprintf(fpe,"%d %s %s %s\n",k.candidate_id,k.candidate_name,k.candidate_email,k.candidate_phone);
    printf("Candidate details updated successfully!\n");
    fclose(fpe);
}
void view_job(){
FILE *fp;
fp = fopen("jobs.txt", "r");
do{
    char id1[100],ttle[100],dcs[100],req[100],ctg[100];
    fgets(id1,100,fp);
    fgets(ttle,100,fp);
    fgets(dcs,100,fp);
    fgets(req,100,fp);
    fgets(ctg,100,fp);
    if(feof(fp)){break;}
    printf("ID: %s",id1);
    printf("Title: %s",ttle);
    printf("Description: %s",dcs);
    printf("Requirements: %s",req);
    printf("Category: %s\n",ctg);
}while(!(feof(fp)));
}