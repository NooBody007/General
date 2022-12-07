import scrapy

#div class="name ellipsis" -- a -- span
#div class="publisher" -- span -- a --span
#div class="author" -- span -- a --span
#a class="next" 
#https://www.kitapyurdu.com/index.php?route=product/best_sellers&list_id=1&filter_in_stock=1&filter_in_stock=1&limit=20&
#page=num
#response.css("div.name.ellipsis a span::text").extract() -- sayfadaki bütün kitaplar
#response.css("div.publisher span a span::text").extract() -- sayfadaki bütün yayıncılar
#response.css("div.author span a span::text").extract() -- sayfadaki bütün yazarlar
#response.css("a.next::attr(href)").extract_first()

class QuotesSpider(scrapy.Spider):
    name = "books"
    start_urls = [
            'https://www.kitapyurdu.com/index.php?route=product/best_sellers&list_id=1&filter_in_stock=1&filter_in_stock=1&limit=20&page=1'
        ]
    page_count = 1
    book_count = 1
    file = open("books.txt","a",encoding="utf-8")

    def parse(self, response):
        book_names = response.css("div.name.ellipsis a span::text").extract()
        book_authors = response.css("div.author span a span::text").extract()
        book_publishers = response.css("div.publisher span a span::text").extract()
        
        i = 0
        while i < len(book_names):
            """yield {
                "name" : book_names[i],
                "author":book_authors[i],
                "publisher":book_publishers[i]
            }"""
            self.file.write("------------------------\n")
            self.file.write(str(self.book_count) + ".\n")
            self.file.write("Kitap Adı: " + book_names[i]+ "\n")
            self.file.write("Yazar: " + book_authors[i]+ "\n")
            self.file.write("Yayınevi: " + book_publishers[i] + "\n")
            self.file.write("------------------------\n")
            self.book_count += 1
            i += 1
        next_url = response.css("a.next::attr(href)").extract_first()
        self.page_count += 1
        if next_url is not None and self.page_count != 6:
            yield scrapy.Request(url=next_url, callback = self.parse)
        else:
            self.file.close()
