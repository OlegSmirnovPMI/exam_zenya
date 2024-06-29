using System;
using System.IO;

class ReadFile
{
    static void Main(string[] args)
    {
        string filePath = @"../../../text.txt"; //не забудь поставить путь свой,приколы rider.
        string fileContent = File.ReadAllText(filePath);
        string[] words = fileContent.Split(new char[] { ',', ' ', '!', '.' }, StringSplitOptions.RemoveEmptyEntries);
        int arrayLength = words.Length;
        int i;
        for (i = 0; i < arrayLength - 1; i += 2) 
        {
            string tmp = words[i];
            words[i] = words[i + 1];
            words[i + 1] = tmp;
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
