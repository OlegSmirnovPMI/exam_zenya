using System;
using System.IO;
using System.Text.Encodings.Web;

class ReadFile
{
    static void Main(string[] args)
    {
        string filePath = @"../../../text.txt"; //не забудь поставить путь свой,приколы rider.
        string fileContent = File.ReadAllText(filePath);
        string[] words = fileContent.Split(new char[] { ',', ' ', '!', '.' }, StringSplitOptions.RemoveEmptyEntries);
        int arrayLength = words.Length;
        int i;
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
                listOfWordsAndSeparates.Add(new string(words[count].Reverse().ToArray()));
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
