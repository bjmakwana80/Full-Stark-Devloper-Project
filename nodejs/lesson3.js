var countries = [
    { name: "Germany", flag: "https://flagpedia.net/data/flags/w580/de.png", continent: "Europe" },
    { name: "United Kingdom", flag: "https://flagpedia.net/data/flags/w580/gb.png", continent: "Europe" },
    { name: "France", flag: "https://flagpedia.net/data/flags/w580/fr.png", continent: "Europe" },
    { name: "Italy", flag: "https://flagpedia.net/data/flags/w580/it.png", continent: "Europe" },
    { name: "Spain", flag: "https://flagpedia.net/data/flags/w580/es.png", continent: "Europe" },
    { name: "Netherlands", flag: "https://flagpedia.net/data/flags/w580/nl.png", continent: "Europe" },
    { name: "Belgium", flag: "https://flagpedia.net/data/flags/w580/be.png", continent: "Europe" },
    { name: "Switzerland", flag: "https://flagpedia.net/data/flags/w580/ch.png", continent: "Europe" },
    { name: "Austria", flag: "https://flagpedia.net/data/flags/w580/at.png", continent: "Europe" },
    { name: "Portugal", flag: "https://flagpedia.net/data/flags/w580/pt.png", continent: "Europe" },
    { name: "Sweden", flag: "https://flagpedia.net/data/flags/w580/se.png", continent: "Europe" },
    { name: "Norway", flag: "https://flagpedia.net/data/flags/w580/no.png", continent: "Europe" },
    { name: "Denmark", flag: "https://flagpedia.net/data/flags/w580/dk.png", continent: "Europe" },
    { name: "Finland", flag: "https://flagpedia.net/data/flags/w580/fi.png", continent: "Europe" },
    { name: "Greece", flag: "https://flagpedia.net/data/flags/w580/gr.png", continent: "Europe" },
    { name: "Poland", flag: "https://flagpedia.net/data/flags/w580/pl.png", continent: "Europe" },
    { name: "Czech Republic", flag: "https://flagpedia.net/data/flags/w580/cz.png", continent: "Europe" },
    { name: "Hungary", flag: "https://flagpedia.net/data/flags/w580/hu.png", continent: "Europe" },
    { name: "Ireland", flag: "https://flagpedia.net/data/flags/w580/ie.png", continent: "Europe" },
    { name: "Slovakia", flag: "https://flagpedia.net/data/flags/w580/sk.png", continent: "Europe" },
    { name: "China", flag: "https://flagpedia.net/data/flags/w580/cn.png", continent: "Asia" },
    { name: "India", flag: "https://flagpedia.net/data/flags/w580/in.png", continent: "Asia" },
    { name: "Japan", flag: "https://flagpedia.net/data/flags/w580/jp.png", continent: "Asia" },
    { name: "South Korea", flag: "https://flagpedia.net/data/flags/w580/kr.png", continent: "Asia" },
    { name: "Indonesia", flag: "https://flagpedia.net/data/flags/w580/id.png", continent: "Asia" },
    { name: "Nigeria", flag: "https://flagpedia.net/data/flags/w580/ng.png", continent: "Africa" },
    { name: "Egypt", flag: "https://flagpedia.net/data/flags/w580/eg.png", continent: "Africa" },
    { name: "South Africa", flag: "https://flagpedia.net/data/flags/w580/za.png", continent: "Africa" },
    { name: "Kenya", flag: "https://flagpedia.net/data/flags/w580/ke.png", continent: "Africa" },
    { name: "Ethiopia", flag: "https://flagpedia.net/data/flags/w580/et.png", continent: "Africa" },
    { name: "United States", flag: "https://flagpedia.net/data/flags/w580/us.png", continent: "North America" },
    { name: "Canada", flag: "https://flagpedia.net/data/flags/w580/ca.png", continent: "North America" },
    { name: "Mexico", flag: "https://flagpedia.net/data/flags/w580/mx.png", continent: "North America" },
    { name: "Cuba", flag: "https://flagpedia.net/data/flags/w580/cu.png", continent: "North America" },
    { name: "Jamaica", flag: "https://flagpedia.net/data/flags/w580/jm.png", continent: "North America" },
    { name: "Brazil", flag: "https://flagpedia.net/data/flags/w580/br.png", continent: "South America" },
    { name: "Argentina", flag: "https://flagpedia.net/data/flags/w580/ar.png", continent: "South America" },
    { name: "Colombia", flag: "https://flagpedia.net/data/flags/w580/co.png", continent: "South America" },
    { name: "Chile", flag: "https://flagpedia.net/data/flags/w580/cl.png", continent: "South America" },
    { name: "Peru", flag: "https://flagpedia.net/data/flags/w580/pe.png", continent: "South America" },
    { name: "Australia", flag: "https://flagpedia.net/data/flags/w580/au.png", continent: "Australia" },
    { name: "New Zealand", flag: "https://flagpedia.net/data/flags/w580/nz.png", continent: "Australia" },
    { name: "Papua New Guinea", flag: "https://flagpedia.net/data/flags/w580/pg.png", continent: "Australia" },
    { name: "Fiji", flag: "https://flagpedia.net/data/flags/w580/fj.png", continent: "Australia" },
    { name: "Solomon Islands", flag: "https://flagpedia.net/data/flags/w580/sb.png", continent: "Australia" }
];
var http = require('http');
var url = require('url');
var server = http.createServer((request, res) => {
    var queryObject = url.parse(req.url, true).query;

    if (!queryObject.continent) {
        res.writeHead(400, { 'Content-Type': 'application/json' });
        res.end(JSON.stringify({ error: 'Continent query parameter is required' }));
        return;
    }

    var continent = queryObject.continent.toLowerCase();
    var filteredCountries = countries.filter(country => country.continent.toLowerCase() === continent);

    res.writeHead(200, { 'Content-Type': 'application/json' });
    res.end(JSON.stringify(filteredCountries));
});

var portno = 8076;
server.listen(portno, () => {
    console.log('Server is listening on port ' + portno);
});