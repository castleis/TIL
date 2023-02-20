# 어간 추출
from nltk.stem import PorterStemmer
from nltk.stem import LancasterStemmer
from nltk.tokenize import word_tokenize

porter_stemmer = PorterStemmer()
lancaster_stemmer = LancasterStemmer()

sentence = "This was not the map we found in Billy Bones's chest, but an accurate copy, complete in all things--names and heights and soundings--with the single exception of the red crosses and the written notes."
tokenized_sentence = word_tokenize(sentence)

print('어간 추출 전 :', tokenized_sentence)
print('포터 스테머 어간 추출 후 :', [porter_stemmer.stem(word) for word in tokenized_sentence])
print('랭커스터 스테머 어간 추출 후 :', [lancaster_stemmer.stem(word) for word in tokenized_sentence])