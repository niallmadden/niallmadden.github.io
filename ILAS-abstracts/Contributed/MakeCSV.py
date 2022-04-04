import glob
import re

def GetAbstract(data_string):
    start = data_string.find('\\maketitle') + 10
    AbsLine = data_string[start:] 
    end = AbsLine.find('\end{doc')
    AbsLine=AbsLine.replace('\n', "\\n")
    return AbsLine.strip()

def GetAuthor(data_string):
    start = data_string.find('\\author{') + 7
    AuthorLine = data_string[start:] 
    end = AuthorLine.find('\n')
    author = AuthorLine[:end] # re.search('author(.+?)%', data).group(1)
    #print("1. Author: ", author)
    Percent = author.find('%')
    if (Percent != -1):
        author = author[:Percent]
    #print("2. Author: ", author,":")
    return author.strip()

def GetAddress(data_string):
    start = data_string.find('\\address{') + 9
    Line = data_string[start:] 
    end = Line.find('\n')
    Address = Line[:end] 
    Percent = Address.find('%')
    if (Percent != -1):
        Address = Address[:Percent]
    CloseCurly = Address.find('}')
    if (CloseCurly != -1):
        Address = Address[:CloseCurly]
    NewLine = Address.find('\\')
    if (NewLine != -1):
        Address = Address[:NewLine]
    return Address.strip()

def GetTitle(data_string):
    start = data_string.find('\\title{') + 6
    Line = data_string[start:] 
    end = Line.find('\n')
    title = Line[:end] # re.search('author(.+?)%', data).group(1)
    return title.strip()


def GetEmail(data_string):
    return re.search('email{(.+?)}', data_string).group(1)

def CountSpaces(this_string):
    count = 0
    for i in this_string:
        if(i.isspace()):
            count=count+1
    return(count)

CSVfile = open('contrib.csv','w')

FirstLine = "fullname;firstname;middlenames;surname;email;affiliation;minikey;title;abstract;;;"+"\n"
CSVfile.write(FirstLine)

list_of_files = glob.glob('./*.tex')           # create the list of file

for file_name in list_of_files:
    print(file_name)
    tex_file = open(file_name, "r")
    full_text = tex_file.read()
    Title = GetTitle(full_text)
    Author = GetAuthor(full_text)
    Names = Author.split()
    NumNameSpaces = CountSpaces(Author)
    FirstName=Names[0][1:].strip()
    if (NumNameSpaces == 1):
        MiddleName = ""
        LastName=Names[1].strip()
    elif (NumNameSpaces == 2):
        MiddleName = Names[1].strip()
        LastName = Names[2].strip()
    else:
        print("Error: need to check ", file_name)
        print("Name = ", author, " but NumNameSpaces=", NumNameSpaces)

        
    Key = "".join(Author.split())
    Email = GetEmail(full_text)
    MiniKey = "contrib" # NM will hack this later
    Address = GetAddress(full_text)
    print("key: ", Key)
    print("author: ", Author, " (", NumNameSpaces, ") : ", \
          FirstName,"-",MiddleName,"-",LastName)
    print("title: ", Title)
    print("Email: ", Email)
    print("Afl  : ", Address)
    
    Abs = GetAbstract(full_text)
    print("Abs: ", Abs)
    CSVLine = Key+";"+FirstName+";"+MiddleName+";"+LastName+";"+Email+";"\
        +Address+";"+MiniKey+";"+Title+";"+Abs+"\n"
    tex_file.close()
    CSVfile.write(CSVLine)
 

CSVfile.close()

