while True:
  try:
    n = int(input())
    books = []
    for i in range(n):
    	x = input()
    	books.append(x)
    
    s_books = sorted(books)
    for obj in s_books:
    	print(obj)
    	
  except EOFError:
    break