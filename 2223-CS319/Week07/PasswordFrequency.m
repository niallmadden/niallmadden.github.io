% Passwords_Frequency.m
%% Find the most frequently occuring entries in a vector
% Author:   Niall Madden (Niall.Madden@UniversityOfGalway.ie
% Date:     Week 7 of 2223-CS319)
clear;
%% Load the Passwords array 
load UserAccount-1e6;
NumberOfPWDs = length(Passwords);
fprintf("Array Passwords has %d entries\n", NumberOfPWDs);
%% Sort the passwords
Passwords = sort(Passwords);
fprintf("\n------------\n");
fprintf("First 5 words sorted are: ");
fprintf("%s\n", Passwords(1:5));

%% Find the most frequently occuring word. 
%   - create a new list of unique words
%   - a corresponding count of the number on instances.
[UniqueWords, ai] = unique(Passwords);
WordFreq    = diff([ai; NumberOfPWDs+1]);

%% Sort by Frequency
% Again use the "sort" function, but keep the "key"
[WordFreq,key]=sort(WordFreq,'descend');
UniqueWords = UniqueWords(key);

%% Output top 10
fprintf("The 10 most common words (and freqs) are:\n");
for i=1:10
   fprintf("\t%10s (%3d)\n", UniqueWords(i), WordFreq(i));
end