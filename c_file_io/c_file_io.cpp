//============================================================================
// Name        : C_File_IO.cpp
// Author      : Pyrad
// Time		   : Jan 14, 2016
// Version     : Ver 1.0
// Copyright   : Copyright reserved by Pyrad
// Description : This is a file to test all C function related to file I/O
//============================================================================

#include <iostream>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

	// Time stamp for quick use
	time_t timestamp;
	time(&timestamp);
	char* timep = ctime(&timestamp);


	const char file_name[] = "tmp_test.txt";
	const char file_name_re[] = "tmp_test_re.txt";
	const char test_string_a[] = "THIS IS A STRING FOR TESTING. A.";
	const char test_string_b[] = "THIS IS A STRING FOR TESTING. B.";
	const char test_string_c[] = "THIS IS A STRING FOR TESTING. C.";
	const char test_string_d[] = "THIS IS A STRING FOR TESTING. D.";
	const char test_string_e[] = "MY HEART WILL GO ON";
	const char test_string_f[] = "THIS IS A STRING FOR TESTING. F.";
	const char buff[] = "GOOD DAYS WILL COME SOON!";


	// check file_name
	int check = access(file_name, 0);
	if(check == 0) {
		printf("File \"%s\" exists!\n", file_name);
		if( access(file_name, 1) == 0) {
			printf("File has execute permission\n");
		}
		if(access(file_name, 2) == 0) {
			printf("File has write permission\n");
		}
		if(access(file_name, 4) == 0) {
			printf("File has read permission\n");
		}
		if(access(file_name, 6) == 0) {
			printf("File has read & write permission\n");
		}

		printf("Remove it...\n");
		if(remove(file_name) == 0) {
			printf("Deleted successfully!\n");
		} else {
			printf("Deletion failed! ERRNO: %d\n", errno);
		}
	} else {
		printf("File %s DOES NOT exist!\n", file_name);
	}
	// Check file_name_re
	check = access(file_name_re, 0);
	if(check == 0) {
		// If file for redirect use exists, delete it
		if(remove(file_name_re)) {
			printf("Deletion for redirect file fail! ERRNO: %d\n", errno);
		}
	}

	printf("Build a new file: %s\n", file_name);
	FILE* fp = fopen(file_name, "w");
	if(!fp) {
		printf("RETURNED. Failed to open file: %s for writing!\n", file_name);
		return -1;
	} else {
		printf("Successfully opened file for writing\n");
	}
	printf("Print message to file \"%s\" ...\n", file_name);
	fprintf(fp, "%s\n", test_string_a);
	fprintf(fp, "%s\n", test_string_b);
	fprintf(fp, "%s\n", test_string_c);
	fprintf(fp, "%s\n", test_string_d);
	// Add time stamp
	printf("Adding time stamp: %s\n", timep);
	fprintf(fp, "%s", timep);
	fprintf(fp, "%s", timep); // Will be replaced at last

	// Move file stream pointer to the beginning of the file
	printf("Moving file pointer to the beginning...\n");
	fseek(fp, 0L, SEEK_SET);
	long fp_pos = ftell(fp);
	printf("File pointer offset(in bytes) to the beginning: %ld\n", fp_pos);
	printf("Insert new messages at the beginning...\n");
	// Insert "GOOD DAYS WILL COME SOON!", 5 bytes x 5 blocks
	fwrite(buff, 5/*bytes*/, 5/*blocks*/, fp);
	// Flush buffer to write to disk
	fflush(fp);

	// Get current fp position(in bytes)
	fpos_t fpp; // "fpos_t" is long long int
	fgetpos(fp, &fpp);
	printf("File pointer offset(in bytes) to the beginning: %lld\n", fpp);

	// Move fp pointer again to the sixth bytes offset to the start
	// Then replace the word with "LOVE"
	// Next move to the start again and replace first word with "BEST"
	fpp = 5;
	fsetpos(fp, &fpp);
	printf("File pointer offset(in bytes) to the beginning: %ld\n", ftell(fp));
	fputs("LOVE", fp);
	printf("File pointer offset(in bytes) to the beginning: %ld\n", ftell(fp));

	rewind(fp);
	printf("File pointer offset(in bytes) to the beginning: %ld\n", ftell(fp));
	fputs("BEST", fp);
	printf("File pointer offset(in bytes) to the beginning: %ld\n", ftell(fp));

	fflush(fp);
	printf("File pointer offset(in bytes) to the beginning: %ld\n", ftell(fp));

	// Check if reach the end of file
	if(feof(fp) == 0)
		printf("Not the end of file!\n");
	else
		printf("Reach the end of file\n");

	// Move to the end of file and insert word "MY HEART WILL GO ON"
	int sen_len = strlen(test_string_e);
	fseek(fp, -sen_len, SEEK_END);
	fputs(test_string_e, fp);

	// Check if reach the end of file
	printf("File pointer offset(in bytes) to the beginning: %ld\n", ftell(fp));
	if (feof(fp) == 0)
		printf("Not the end of file!\n");
	else
		printf("Reach the end of file\n");


	// Get file descriptors
	printf("File descriptor of 'stdin': %d\n", fileno(stdin));
	printf("File descriptor of 'stdout': %d\n", fileno(stdout));
	printf("File descriptor of 'stderr': %d\n", fileno(stderr));
	printf("File descriptor of 'fp': %d\n", fileno(fp));



	printf("Closing file...\n");
	fclose(fp);

	printf("\nRedirect test\n");
	// Redirect file stream
	if(!freopen(file_name_re, "w", stdout)) {
		printf("Failed to redirect file!\n");
		return -1;
	}
	// Messages to redirect file, then close the re-directed file
	printf("%s\n", test_string_f);
	fclose(stdout);
	// Restore stdout
	freopen("CON", "w", stdout);
	printf("Restored messages to STDOUT\n");

	return 0;
}

