import os
import hashlib
from bs4 import BeautifulSoup

def hash_filename(filename):
    return hashlib.md5(filename.encode()).hexdigest()

def parse_document(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    soup = BeautifulSoup(content, 'lxml')

    paragraphs = [paragraph.text for paragraph in soup.find_all('p')]

    return {
        'paragraphs': paragraphs
    }

def parse_documents_in_folder(folder_path):
    """Parse all XHTML and HTML files in the given folder and store the content in a dictionary."""
    documents = {}
    
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith('.html') or file.endswith('.xhtml'):
                file_path = os.path.join(root, file)
                file_hash = hash_filename(file)
                parsed_content = parse_document(file_path)
                documents[file_hash] = parsed_content

    return documents

if __name__ == "__main__":
    folder_path = 'data/docs.gl/gl4'
    documents = parse_documents_in_folder(folder_path)

