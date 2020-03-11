from urllib.request import urlopen
import bs4

html_str = "<html><div>test</div></html>"
bs_obj = bs4.BeautifulSoup(html_str, 'html.parser')

print(type(bs_obj))
print(bs_obj)
print(bs_obj.find('div'))

# url = "https://www.naver.com"
# html = urlopen(url)

# print(html.read())