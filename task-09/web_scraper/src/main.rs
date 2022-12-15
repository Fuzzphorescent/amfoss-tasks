use std::fs::File;
use std::io::Write;

fn main() {
    let response = reqwest::blocking::get(
        "https://crypto.com/price",
    )
    .unwrap()
    .text()
    .unwrap();

    let document = scraper::Html::parse_document(&response);

    let name_selector = scraper::Selector::parse(".css-rkws3").unwrap();
    let price_selector = scraper::Selector::parse(".css-b1ilzc").unwrap();
    let change_ss 34elector = scraper::Selector::parse(".css-1b7j986>p").unwrap();
    let volume_marketcap_selector = scraper::Selector::parse(".css-1nh9lk8").unwrap();
    let row_selector = scraper::Selector::parse(".css-1cxc880").unwrap();

    let rows = document.select(&row_selector);
    let details = rows.map(|row| {
    
        let name = row.select(&name_selector).next().unwrap().inner_html();
        let price = row.select(&price_selector).next().unwrap().inner_html();
        let change = row.select(&change_selector).next().unwrap().inner_html();
        let mut iter = row.select(&volume_marketcap_selector);
        let volume = iter.next().unwrap().inner_html();
        let marketcap = iter.next().unwrap().inner_html();
        return (name, price, change, volume, marketcap);
    });

    let mut file = File::create("Crypto.csv").expect("Failed to create a file.");

    details
        .zip(1..51)
        .for_each(|(item, number)| writeln!(file, "\"{}\",\"{}\",\"{}\",\"{}\",\"{}\",\"{}\"", number, item.0, item.1, item.2, item.3, item.4).expect("Failed to write."));
}
