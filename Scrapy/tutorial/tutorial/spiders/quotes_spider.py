import scrapy


class QuotesSpider(scrapy.Spider):
    name = "quotes"
    quote_count = 1
    file = open("quotes.txt","a",encoding="utf-8")
    start_urls =[
        'http://quotes.toscrape.com/page/1/'
    ]

    def parse(self, response):

        for quote in response.css("div.quote"):
            title = quote.css("span.text::text").extract_first()
            author = quote.css("small.author::text").extract_first()
            tags = quote.css("div.tags a.tag::text").extract()
            self.file.write(str(self.quote_count) + "**************************\n")
            self.file.write("Alıntı : " + title + "\n")
            self.file.write("Alıntı Sahibi : " + author + "\n")
            self.file.write("Etiketler : " + str(tags) + "\n")
            self.quote_count += 1
        next_url = response.css("li.next a::attr(href)").extract_first()
        if next_url is not None:
            next_url = "http://quotes.toscrape.com"+next_url
            yield scrapy.Request(url=next_url, callback=self.parse)
        else:
            self.file.close()

"""
scrapy "url"
response -- 200
response.css("title") -- class
response.css("title").extract() sadece data geliyor
response.css("title::text").extract() sadece text verisi liste olarak geliyor
response.css("title::text").extract()[0] bu listedeki 0. indexi alır.  bu [0] noktadan önce de yazılabilir.
response.css("title::text").extract_first() direkt text alanını verir.

response.xpath("//title") xpath'e göre alır
response.xpath("//title").extract_first() sadece data alır
response.xpath("//title/text()").extract_first() direkt text alanını alır.

-----------
content = response.css("div.quote") -- class'ı quote olan div'leri alıyor.(liste döner)
quote = response.css("div.quote")[0]
title = quote.css("span.text").extract_first() -- quote içindeki span'ın class'ı text olanını alır ve döndürür.(html)
title = quote.css("span.text::text").extract_first() -- span'ın class'ı text olanının text verisini döndürür.(text)

author = quote.css("small.author").extract_first() -- small'un class'ı author olan verisini alır (html)
author = quote.css("small.author::text").extract_first() -- small'un class'ı author olan verisinin text'ini alır.(text)

tags = quote.css("div.tags a.tag::text").extract() -- birden fazla alma
"""


