impl Solution {
     pub fn roman_to_int(s: String) -> i32 {
         let values: Vec<(i32, &'static str)> = vec![
             (1000, "M"),
             (900, "CM"),
             (500, "D"),
             (400, "CD"),
             (100, "C"),
             (90, "XC"),
             (50, "L"),
             (40, "XL"),
             (10, "X"),
             (9, "IX"),
             (5, "V"),
             (4, "IV"),
             (1, "I"),
         ];
         
         let mut total = 0;
         let mut match_val = 0;
         
         for i in values.iter() {
             while match_val + i.1.len() <= s.len() && i.1 == &s[match_val..match_val + i.1.len()] {
                 match_val += i.1.len();
                 total += i.0;
                 
                 if match_val >= s.len() {
                     return total;
                 }
             }
         }
         total
     }
}

fn main() {
    println!("{}", Solution::roman_to_int("MCMXCIV".to_string()));
}