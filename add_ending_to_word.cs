using System;
using System.IO;
using System.Text;

class ReadFile
{
    static void Main(string[] args)
    {
        string filePath = @"../../../text.txt"; //не забудь поставить путь свой,приколы rider.
        string fileContent = File.ReadAllText(filePath);
        string[] words = fileContent.Split(new char[] { ',', ' ', '!', '.' }, StringSplitOptions.RemoveEmptyEntries);
        int arrayLength = words.Length;
        int i;
        char[] arrayOfVowels = {'а','у','о','ы','э','е','и','ю','я'};
        for (i = 0; i < arrayLength; i++)
        {
           
                for (int k = 0; k < words[i].Length; k++)
                {
                    bool contains = arrayOfVowels.Any(symbol => symbol == char.ToLower(words[i][k]));
                    if (contains)
                    {

                        StringBuilder sb = new StringBuilder(words[i]);
                        sb.Remove(k, 1); 
                        sb.Insert(0, words[i][k] + "циус"); 
                        words[i] = sb.ToString();
                        break;
                    }
                }

        }

        List<string> listOfWordsAndSeparates = new List<string>();
        int lenghOfText = fileContent.Length;
        int count = 0;
        i = 0;
        while (i < lenghOfText) {
            if (fileContent[i] == ','
                || fileContent[i] == ' '
                || fileContent[i] == '!'
                || fileContent[i] == '.')
            {
                listOfWordsAndSeparates.Add(new string(fileContent[i],1));
            }
            else
            {
                listOfWordsAndSeparates.Add(words[count]);
                while (i < lenghOfText &&
                       fileContent[i] != ','
                       && fileContent[i] != ' '
                       && fileContent[i] != '!'
                       && fileContent[i] != '.')
                {
                    i++;
                }

                i--;
                count++;
            }

            i++;
        }
        foreach (string value in listOfWordsAndSeparates)
        {
            Console.Write(value);
        }
    }
    
}
