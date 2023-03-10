#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>



#define MAX_PASSWORD_LENGTH 50
#define PASSWORD_FILENAME "psw.txt"
void sigint_handler(int sig)
{

}
int check_password() {
   printf("def os beta \n");
    FILE* password_file = fopen(PASSWORD_FILENAME, "r");
    if (password_file == NULL) {
        char new_password[MAX_PASSWORD_LENGTH];
        printf("No password file found. Please enter a new password: ");
        scanf("%s", new_password);
        FILE* new_file = fopen(PASSWORD_FILENAME, "w");
        fprintf(new_file, "%s", new_password);
        fclose(new_file);
        printf("Password saved. You may proceed.\n");
        return 1;
    } else {
        char password[MAX_PASSWORD_LENGTH];
        printf("Password: ");
        scanf("%s", password);
        char password_from_file[MAX_PASSWORD_LENGTH];
        fscanf(password_file, "%s", password_from_file);
        fclose(password_file);
        if (strcmp(password, password_from_file) == 0) {
            printf("Password accepted. You may proceed.\n");
            return 1;
        } else {
            printf("Incorrect password.\n");
            return 0;
        }
    }
}

int text_editor() {
  printf("Welcome to editit 1.1.0\n");
    printf("Made by shourdev,open source and contributions from many developers! https://github.com/shourdev/editit \n");
    printf("Enter the name of the file you want to open or create: ");
    char file_name[100];
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "r+"); // Open the file in read & write mode
    if (file == NULL)
    {
        file = fopen(file_name, "w+"); // Create the file in read & write mode
        if(file == NULL){
            printf("Error opening/creating file\n");
            return 1;
        }
    }

    printf("\nFile Content:\n");
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c);
    }
    rewind(file); // Move the file pointer to the beginning of the file

    printf("\n\nType your changes and press enter. Type :gotoit to go to a line, :catit to see how the file is now and :quitit to save and exit.\n");
    char input[100];
    int i = 0;
    while (1)
    {
        printf(">> ");
        fflush(stdin);
        fgets(input, 99, stdin);
        input[strlen(input) - 1] = 0;
        if (strcmp(input, ":quitit") == 0)
        {
            break;
        }
        else if (strcmp(input, ":gotoit") == 0)
        {
            int j = 0, l = 1, n;
            printf("What line you want to go? ");
            scanf("%d", &n);
            rewind(file);
            while (l != n)
            {
                j++;
                if(fgetc(file) == '\n'){
                    l++;
                }
            }
            i = j+1;
            fseek(file, j+1, SEEK_SET);
        }
        else if (strcmp(input, ":catit") == 0)
        {
            char c;
            rewind(file);
            while ((c = fgetc(file)) != EOF)
            {
                putchar(c);
            }
            fseek(file, i, SEEK_SET);
        }
        else
        {
            fputs(input, file); // Write the input to the file
            i += strlen(input);
        }
    }

    fclose(file);
    return 0;
}
void calculator() {
  double num1, num2, result;
  char operator;

  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  printf("Enter second number: ");
  scanf("%lf", &num2);

  switch (operator) {
    case '+':
      result = num1 + num2;
      printf("%.1lf + %.1lf = %.1lf\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("%.1lf - %.1lf = %.1lf\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("%.1lf * %.1lf = %.1lf\n", num1, num2, result);
      break;
    case '/':
      result = num1 / num2;
      printf("%.1lf / %.1lf = %.1lf\n", num1, num2, result);
      break;
    default:
      printf("Invalid operator\n");
  }
  
  char exit[100];
  printf("Type exit to go back to command stage: ");
  scanf("%s",exit);
  if(strcmp(exit,"exit")==0){
    return;
  }
}
void rmf() {
    char file_name[100];
    printf("Enter the name of the file you want to delete: ");
    scanf("%s", file_name);

    int status = remove(file_name);
    if (status == 0) {
        printf("%s was successfully deleted\n", file_name);
    } else {
        printf("Error deleting file\n");
    }
}
void list_files() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (".")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return;
    }
}
int main() {
signal(SIGINT, sigint_handler);

    int password_accepted = 0;
    while (!password_accepted) {
        password_accepted = check_password();
    }
 
  char input[100];

  while (1) {
    printf("defshell@def-os: ");
    scanf("%s", input);

    if (strcmp(input, "calc") == 0) {
      calculator();
        } else if (strcmp(input, "editit") == 0) {
            text_editor();
    }
    else if (strcmp(input, "about") == 0) {
            printf("Def-os is an simple os made by Shourjjo Majumder | https://github.com/shourdev/def-os | For donation I accept Bitcoin, here is my address bc1qyr4rv920xgmyht5t2cw4kqlm8pcmj4u0dkg47h \n");
    }
	 
    else if (strcmp(input, "li") == 0) {
            list_files(); }
    else if(strcmp(input,"rmf") == 0)
    {
      rmf();
    }
     else if (strcmp(input, "help") == 0) {
           printf("Commands:\n");
      printf("- calc: runs the calculator application\n");
      printf("- exit: Exits the program\n");
      printf("- editit: A text editor\n");
      printf("- li: List all the files and folders\n");
      printf("- about: About this os\n");
      printf("- help: List all the commands\n");
      printf("- rmf: Remove a file\n");
      printf("For more help checkout our guide at https://github.com/shourdev/def-os/wiki/Commands \n");
    } else if (strcmp(input, "exit") == 0) {
      printf("Exiting the os...\n");
      break;
    } else {
      printf("Invalid command. Type 'help' for a list of commands.\n");
    }
  }

  return 0;
}
