#include "whale.h"
#include "memory.h"
#include <stdio.h>
#include <string.h>

// File: parser.c

// Ubah fungsi ini agar tidak mengembalikan pointer lokal
void get_val(Token t, char *buffer) {
    if (t.type == T_IDENTIFIER) {
        char *val = get_variable(t.value);
        if (val) strcpy(buffer, val);
        else strcpy(buffer, t.value);
    } else {
        strcpy(buffer, t.value);
    }
}

 // File: parser.c
void parse_and_execute(Token tokens[], int count) {
    if (count >= 3 && tokens[1].type == T_ASSIGN) {
        set_variable(tokens[0].value, tokens[2].value);
    }
        else if (tokens[0].type == T_SAY) {
        char result[512] = ""; // 1. Siapkan wadah kosong (buffer)

        // 2. Loop untuk mengumpulkan SEMUA bagian
        for (int i = 1; i < count; i += 2) {
            char val[256];
            get_val(tokens[i], val); // Ambil nilai variabel/string
            
            strcat(result, val);     // 3. Gabungkan ke dalam wadah (result)
            
            // Cek apakah ada operator '+' yang tidak diikuti token (error handling)
            if (i + 1 < count && tokens[i+1].type != T_PLUS) {
                printf("Parser Error: Mengharapkan '+', ketemu '%s'\n", tokens[i+1].value);
                return;
            }
        }
        // 4. PRINT HANYA SEKALI di sini!
        printf("%s\n", result); 
    }
  }

