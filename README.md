<h1>Find String In Files</h1>

<p>This C++ program allows you to search for a specific text string within files in a chosen folder. It provides a user-friendly command-line interface and offers customizable search options.</p>

<h2>Features</h2>

<ul>
  <li>Search for a specific text string within files</li>
  <li>Choose a folder for the search</li>
  <li>Option to include subfolders in the search</li>
  <li>Specify whether the search is case-sensitive</li>
  <li>Displays the filenames and line numbers where the text is found</li>
  <li>Option to reload and search again</li>
</ul>

<h2>Getting Started</h2>

<h3>Prerequisites</h3>

<ul>
  <li>C++ compiler</li>
  <li>Standard Template Library (STL)</li>
</ul>

<h3>Usage</h3>

<ol>
  <li>Clone the repository or download the source code files.</li>
  <li>Compile the source code using a C++ compiler.</li>
  <li>Run the compiled executable.</li>
  <li>Follow the on-screen instructions to perform the search.</li>
</ol>

<pre><code>$ g++ Find-String-In-Files.cpp -o Find-String-In-Files
$ ./Find-String-In-Files</code></pre>

<h3>Example</h3>

<pre><code>Folder location:
/path/to/folder

Search in subfolders as well? (y/n): y

Case sensitive? (y/n): n

Text to search for:
example

Found the text (line 3) in the file /path/to/folder/file.txt
Found the text (line 7) in the file /path/to/folder/subfolder/another_file.txt

Reload the program? (y/n): n
</code></pre>

<h2>Contributing</h2>

<p>Contributions are welcome! If you have any suggestions, bug fixes, or improvements, please submit a pull request.</p>

<h2>License</h2>

<p>This project is licensed under the <a href="#">MIT License</a>.</p>
