#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COMMAND (argv[1])
#define OFFSET *argv[2]
#define PATHIN (argv[3])
#define PATHOUT (argv[4])

/// //Encode foo - gets a text encrypting it and copies the encrypted text to another string
/// \param s string - to encrypt
/// \param k represents the offset
/// \param encrypted - encrypted string
void encode (char s[], char k, char *encrypted)
{
  if (k > 0)
    {
      for (int i = 0; i <= strlen (s); i++)
        {
          if (s[i] >= 'a' && s[i] <= 'z')
            {
              s[i] += k;
            }
          if (s[i] > 'z')
            {
              s[i] = s[i] - 'z' + 'a' - 1;
            }
          if ((s[i] >= 'A' && s[i] <= 'Z'))
            {
              s[i] += k;
            }
          if (s[i] > 'z')
            {
              s[i] = s[i] - 'Z' + 'A' - 1;
            }

        }
    }
  if (k < 0)
    {
      for (int i = 0; i <= strlen (s); i++)
        {
          if (s[i] >= 'a' && s[i] <= 'z')
            {
              s[i] -= k;
            }
          if (s[i] < 'a')
            {
              s[i] = s[i] + 'z' - 'a' + 1;
            }
          if (s[i] >= 'A' && s[i] <= 'Z')
            {
              s[i] -= k;
            }
          if (s[i] < 'A')
            {
              s[i] = s[i] + 'Z' - 'A' + 1;
            }
        }
    }
  strcpy (encrypted, s);
}

void decode (char s[], char k, char *decoded)
{
  if (k >= 0)
    {
      for (int i = 0; i <= strlen (s); i++)
        {
          printf("%c", s[i]);
          if (s[i] >= 'a' && s[i] <= 'z')
            {
              s[i] = s[i] + k;
            }
          if (s[i] < 'a')
            {
              s[i] = s[i] + 'z' - 'a' + 1;
            }
          if (s[i] >= 'A' && s[i] <= 'Z')
            {
              s[i] = s[i] + k;
            }
          if (s[i] < 'A')
            {
              s[i] = s[i] + 'Z' - 'A' + 1;
            }
        }
    }
  if (k < 0)
    {
      k = -k;
      for (int i = 0; i <= strlen(s); i++)
        {
          if (s[i] >= 'a' && s[i] <= 'z')
            {
              s[i] -= k;
            }
          if (s[i] > 'z')
            {
              s[i] = s[i] - 'z' + 'a' - 1;
            }
          if ((s[i] >= 'A' && s[i] <= 'Z'))
            {
              s[i] -= k;
            }
          if (s[i] > 'z')
            {
              s[i] = s[i] - 'Z' + 'A' - 1;
            }
        }
    }
  strcpy (decoded, s);
}

int main (int argc, char *argv[])
{

  char str[200] = "Hello, World!";
  char str1[200];
  encode(str, 3 ,str1);
  printf("%s", str);
  decode(str1, 3, str);
  printf("%s",str1);

//  if (strcmp (argv[1], "encode") != 0)
//    {
//      if (strcmp (argv[1], "decode") != 0)
//        {
//          if (strcmp (argv[1], "check") != 0)
//            {
//              fprintf (stderr, "%s\n", "The given command is invalid");
//            }
//
//        }
//
//    }
//  char text[200];
//  // Encoding Operation
//
//  if (strcmp (COMMAND, "encode") == 0)
//    {
//      if (argc != 5)
//        {
//          fprintf (stderr, "%s\n", "Usage:cipher<encode|decode><k><source path file><output path file>");
//        }
//      char encryptedTxt[200];
//      FILE *file1 = fopen (argv[3], "r");
//      if (file1 == NULL)
//        {
//          fprintf (stderr, "%s\n", "The given file is invalid");
//        }
//      fgets (text, 200, file1);
//      encode (text, OFFSET, encryptedTxt);
//      FILE *fout = fopen (argv[4], "w");
//      if (fout == NULL)
//        {
//          fprintf (stderr, "%s\n", "The given file is invalid");
//        }
//      fprintf (fout, encryptedTxt);
//      fclose (fout);
//    }
//  //Decoding Operation
//  if (strcmp (argv[1], "decode") == 0)
//    {
//      if (argc != 5)
//        {
//          fprintf (stderr, "%s\n", "Usage:cipher<encode|decode><k><source path file><output path file>");
//        }
//      char decodedTxt[200];
//      FILE *fIn = fopen (argv[3], "r");
//      if (fIn == NULL)
//        {
//          fprintf (stderr, "%s\n", "The given file is invalid");
//        }
//      fgets (text, 200, fIn);
//      decode (text, *argv[2], decodedTxt);
//      FILE *fout = fopen (argv[4], "w");
//      if (fout == NULL)
//        {
//          fprintf (stderr, "%s\n", "The given file is invalid");
//        }
//      fprintf (fout, decodedTxt);
//      fclose (fout);
//    }
//
//  //Check Operation
//  if (strcmp (argv[1], "check") == 0)
//    {
//      if (argc != 4)
//        {
//          fprintf (stderr, "%s\n", "Usage:cipher<check><source path file><output path file>");
//        }
//      char textin[200];
//      char textout[200];
//      char encryptext[200];
//      FILE *fIn = fopen (argv[3], "r");
//      if (fIn == NULL)
//        {
//          fprintf (stderr, "%s\n", "The given file is invalid");
//        }
//      fgets (textin, 200, fIn);
//      FILE *fout = fopen (argv[4], "r");
//      if (fout == NULL)
//        {
//          fprintf (stderr, "%s\n", "The given file is invalid");
//        }
//      fgets (textout, 200, fout);
//      for (int k = 0; k <= 25; k++)
//        {
//          encode (textin, k, encryptext);
//          if (strcmp (encryptext, textout) == 0)
//            {
//              fprintf (stdout, "%s %d\n", "Valid Encrypting with k =", k);
//              break;
//            }
//        }
//
//    }

  return 0;
}
