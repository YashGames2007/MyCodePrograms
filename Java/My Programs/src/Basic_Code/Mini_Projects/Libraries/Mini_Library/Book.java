package Basic_Code.Mini_Projects.Libraries.Mini_Library;

public class Book {
    private String name;
    private String author_Name;
    private String book_Type;
    private int total_Pages;
    private int price;

    public Book(String name, String author_Name, String book_Type, int total_Pages, int price) {
        this.name = name;
        this.author_Name = author_Name;
        this.book_Type = book_Type;
        this.total_Pages = total_Pages;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public String getAuthor_Name() {
        return author_Name;
    }

    public String getBookType() {
        return book_Type;
    }

    public int getTotal_Pages() {
        return total_Pages;
    }

    public int getPrice() {
        return price;
    }

    public boolean equals(Book other_Book) {
        boolean name = (this.name == other_Book.name);
        boolean author_Name = (this.author_Name == other_Book.author_Name);
        boolean type = (this.book_Type == other_Book.book_Type);
        boolean total_Pages = (this.total_Pages == other_Book.total_Pages);
        boolean price = (this.price == other_Book.price);

        if (name && author_Name && type && total_Pages && price) {
            return true;
        }
        return false;
    }
}