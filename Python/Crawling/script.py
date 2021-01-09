from urllib.request import urlopen
from urllib.error import URLError

url = 'https://www.feelway.com'
try:
	html = urlopen(url).read()
except urllib2.URLError as e:
	html = None

print(html)
