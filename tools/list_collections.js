function getReadableFileSizeString(fileSizeInBytes) {
    var i = -1;
    var byteUnits = [' kB', ' MB', ' GB', ' TB', 'PB', 'EB', 'ZB', 'YB'];
    do {
        fileSizeInBytes = fileSizeInBytes / 1024;
        i++;
    } while (fileSizeInBytes > 1024);

    return Math.max(fileSizeInBytes, 0.1).toFixed(1) + byteUnits[i];
};

function main() {
    var conn = new Mongo("localhost:27017");
    var list_collections = ["Short_2", "Short_3"];
    var m = new Map();

    for(var i = 0; i < list_collections.length; i++) {
        var db = conn.getDB(list_collections[i]);

        var collectionNames = db.getCollectionNames(), stats = [];

        collectionNames.forEach(function (n) { stats.push(db[n].stats()); });
        stats = stats.sort(function(a, b) { return b['size'] - a['size']; });


        for (var c in stats) {
            stats[c]['ns'] = stats[c]['ns'].replace(list_collections[i] + '.', '');

            var size = stats[c]['size'];
            var storageSize = stats[c]['storageSize'];

            if(m[stats[c]['ns']] === undefined) {
                m[stats[c]['ns']] = {size: size, storageSize: storageSize};
            }
            else {
                var final_size = m[stats[c]['ns']].size + size;
                var final_storage_size = m[stats[c]['ns']].storageSize + storageSize;
                m[stats[c]['ns']] =  {size: final_size, storageSize: final_storage_size};
            }
        }
    }

    for (var name_key in m) {
        var c = m[name_key];
        if(c.size !== undefined) {
            print(name_key + ": " + getReadableFileSizeString(c.size) + " (" + getReadableFileSizeString(c.storageSize) + ")");
        }
    }

}
main()
