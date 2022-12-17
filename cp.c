#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <utime.h>
#include <time.h>
extern int errno;
int main(int argc, char* argv [])
{
    int copied_info = 0;
    const struct option long_option[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"verbose", no_argument, NULL, 'v'}, 
        {"interactive", no_argument, NULL, 'i'},
        {"force", no_argument, NULL, 'f'},
        {"preserve", no_argument, NULL, 'p'},
        {NULL, no_argument, NULL, 0}
    };
	int long_index;
    int opt;
    const char short_option[] = "hvifp";
    
    int flag_h = 0, flag_v = 0, flag_i = 0, flag_f = 0, flag_p = 0;


    while((opt = getopt_long(argc, argv, short_option, long_option, &long_index)) != -1)
    {
        switch(opt)
        {
        case 'h': flag_h = 1;
            break;
        case 'v': flag_v = 1;
            break;
        case 'i': flag_i = 1;
            break;
        case 'f': flag_f = 1;
            break;
        case 'p': flag_p = 1;
            break;
        }
    }


    if (flag_h == 1)
    {
        printf("this program copies all the information from my the first file to the second file\n");
        return 0;
    }
    const char* first_file;
    const char* second_file;
    if (argc > 2 && (argv[optind] != NULL) && (argv[optind + 1] != NULL))
    {
        first_file = argv[optind];
        second_file = argv[optind + 1];
        
        FILE* f1 = fopen(first_file, "r");
        FILE* f2 = fopen(second_file, "w");

        if (f2 == NULL && (errno == 13))
        {
            // perror("happened error");  
            if (flag_f == 1)
            {
                remove(second_file);
                f2 = fopen(second_file, "w");
            }
        }
        if (f2 != NULL)
        {
            
            struct stat st;
            fstat(fileno(f1), &st);
            int size_buf = st.st_size;
            char* buf = (char*) calloc(size_buf + 1, sizeof(char));
            int read_info = fread(buf, sizeof(char), size_buf, f1);

            

            if (flag_i == 1)
            {
                DIR* d = opendir(".");
                struct dirent* drn;
                char* my_files[15];
                int counter = 0;
                while ((drn = readdir(d)) != NULL)
                {
                    my_files[counter] = (char*)drn->d_name; 
                    counter++;
                }
                int i = 0;
                for (i; i < counter; i++)
                {
                    if (strcmp(my_files[i], argv[optind + 1]) == 0)
                    {
                        printf("do you want to continue?\n");
                        printf("y/n?\n");
                        char com;
                        scanf("%c", &com);
                        if (com == 'y')
                        {
                            copied_info = fwrite(buf, sizeof(char), size_buf, f2);
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                }
            if (copied_info == 0)
            {
                copied_info = fwrite(buf, sizeof(char), size_buf, f2);
            }
            if ((copied_info == read_info))
            {
                if (flag_v == 1)
                {
                    const char* command = argv[optind + 2];
                    printf("%s -> %s\n", first_file, second_file);
                }
            }
            fclose(f1);
            fclose(f2);
            if (flag_p == 1)
            {
                f1 = fopen(first_file, "r");
                f2 = fopen(second_file, "w");
                if (errno != EACCES)
                    fwrite(buf, sizeof(char), size_buf, f2);

                struct stat *buf = (struct stat*) calloc (1, sizeof (*buf));
                stat (first_file, buf);

                char cmd_st_mode[20];
                
                int u = 0;
                if (buf->st_mode & S_IRUSR) {u += 4;}
                if (buf->st_mode & S_IWUSR) {u += 2;}
                if (buf->st_mode & S_IXUSR) {u += 1;}
                u *= 100;
                
                int g = 0;
                if (buf->st_mode & S_IRGRP) {g += 4;}
                if (buf->st_mode & S_IWGRP) {g += 2;}
                if (buf->st_mode & S_IXGRP) {g += 1;}
                g *= 10;
                
                int oth = 0;
                if (buf->st_mode & S_IROTH) {oth += 4;}
                if (buf->st_mode & S_IWOTH) {oth += 2;}
                if (buf->st_mode & S_IXOTH) {oth += 1;}
                int perm = u + g + oth;
                sprintf (cmd_st_mode, "chmod %d %s", perm, second_file);
                system (cmd_st_mode);

                size_t uid = getuid();
                size_t gid = getgid();
                char cmd_uid[20];
                char cmd_gid[20];
                sprintf (cmd_uid, "chown %ld %s", uid, second_file);
                sprintf (cmd_gid, "chown %ld %s", gid, second_file);

                system (cmd_uid);
                system (cmd_gid);
                
                struct utimbuf Time = {buf->st_atim.tv_sec, buf->st_mtim.tv_sec};
                fclose(f1);
                fclose(f2);
                struct stat *bufOutput = (struct stat*) calloc (1, sizeof (*bufOutput));
                stat (second_file, bufOutput);
                utime (second_file, &Time);
            }

            free(buf);
        }
    }
    return 0;
}
