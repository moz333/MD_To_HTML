#include <bits/stdc++.h>
using namespace std;
string ConvertToHTML(const string &content)
{
    string line = content;
    if (content.rfind("### ", 0) == 0)
    {
        return "<h3>" + content.substr(4) + "</h3>";
    }
    else if (content.rfind("## ", 0) == 0)
    {
        return "<h2>" + content.substr(3) + "</h2>";
    }

    else if (content.rfind("# ", 0) == 0)
    {
        return "<h1>" + content.substr(2) + "</h1>";
    }
    else if (line.rfind("* ", 0) == 0)
    {
        size_t start = line.find("* ", 0);
        size_t pos_start = line.find("**", start + 2);
        while (start != string::npos)
        {
            size_t pos_end = line.find("**", pos_start + 2);
            if (pos_end != string::npos)
            {
                line.replace(pos_start, 2, "<strong>");
                line.replace(pos_end + 6, 2, "</strong>");
                pos_start = line.find("**", pos_end);
            }
            else
                break;
        }
        return "<li>" + line.substr(2) + "</li>";
    }

    else if (line.find("**") != string::npos)
    {
        size_t start = line.find("**");
        // size_t end = line.find("**", start + 2);
        while (start != string::npos)
        {
            size_t end = line.find("**", start + 2);
            if (end != string::npos)
            {
                string boldItem = line.substr(start + 2, end - start - 1);
                // string newItem = "<strong>" + boldItem + "</strong>"  ;
                line.replace(start, 2, "<strong>");
                line.replace(end + 6, 2, "</strong>");
                start = line.find("**", end);
            }
            else
                break;
        }
        return line;
    }
    else if (content.find("![") != string::npos)
    {
        size_t start = line.find("!");
        size_t buttonS = line.find("[", start + 1);
        size_t buttonE = line.find("]", buttonS + 1);
        size_t linkS = line.find("{", buttonE + 1);
        size_t linkE = line.find("}", linkS + 1);
        string buttonName = line.substr(buttonS + 1, buttonE - buttonS - 1);
        string link = line.substr(linkS + 1, linkE - linkS - 1);
        return "<p>" + line.substr(0, buttonS - 1) + " " + "<a href =\"" + link + "\">" + buttonName + "</a>" + "." + "</p>";
    }
    else if (content.find("|", 0) == 0)
    {
        size_t start = line.find("|", 0);
        while (start != string::npos)
        {
            size_t end = line.find("|", start + 1);
            if (end != string::npos)
            {
                line.replace(start, 1, "<table border =\"1\"><tr><td>");
                line.replace(end + 26, 1, "</td></tr></table>");
                start = line.find("|", end + 1);
            }
            else
                break;
        }
        return line;
    }
    else
        return line;
}

int main()
{

    string content;
    ifstream inputFile("D:/zubair/resume/New folder/md_to_html/test/sample.md.txt");

    ofstream outputFile("D:/zubair/resume/New folder/md_to_html/output/result.html");

    if (inputFile.is_open())
    {

        while (getline(inputFile, content))
        {
            string convertedContent = ConvertToHTML(content);
            outputFile << convertedContent << endl;
        }
        inputFile.close();
        outputFile.close();
    }

    else
    {
        cout << "couldn't open" << endl;
    }
}